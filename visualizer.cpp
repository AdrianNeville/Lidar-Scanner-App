#include "visualizer.h"
#include "gridvertices.h"

#include <QFileInfo>
#include <QOpenGLVersionProfile>
#include <GL/GL.h>

#include <deque>
#include "constants.h"
#include "helpers/TransformHelper.h"
#include "colorutils.h"

static int timer_interval = 10;

Visualizer::Visualizer(QWidget *parent):QOpenGLWidget(parent)
{
    // setFixedSize(700,400);

    qDebug() << "[Visualizer] Constructor called";
    startTimer(timer_interval);
    setFocusPolicy(Qt::StrongFocus);
    pc_handler = new PointCloudHandler(this);


    connect(pc_handler, &PointCloudHandler::notifyPosUpdate, this, &Visualizer::handlePosUpdate);
    connect(pc_handler, &PointCloudHandler::updateByLoadSession, this, &Visualizer::updateByLoadSession);
}

Visualizer::~Visualizer(){
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &colorbuffer);
    glDeleteBuffers(1, &gridbuffer);
}

void Visualizer::loadPCD(const QString& path) {
    int index = pc_handler->getCurrentKeyframeIndex();
    if (pc_handler->loadFromFile(path, index)) {
        QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

        const GLfloat* vertices = pc_handler->getVertices(index);
        const GLubyte* colors = pc_handler->getColors(index);
        int vertexCount = pc_handler->getVertexCount();

        if (index >= static_cast<int>(keyframeVBOs.size())) {
            keyframeVBOs.resize(keyframeVBOs.size() + 1);
        }

        KeyframeVBO& vboData = keyframeVBOs[index];

        if (vboData.vbo) f->glDeleteBuffers(1, &vboData.vbo);
        f->glGenBuffers(1, &vboData.vbo);
        f->glBindBuffer(GL_ARRAY_BUFFER, vboData.vbo);
        f->glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

        if (vboData.colorBuffer) f->glDeleteBuffers(1, &vboData.colorBuffer);
        f->glGenBuffers(1, &vboData.colorBuffer);
        f->glBindBuffer(GL_ARRAY_BUFFER, vboData.colorBuffer);
        f->glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(GLubyte), colors, GL_STATIC_DRAW);

        vboData.vertexCount = vertexCount;

        update();  // Trigger redraw
    } else {
        qWarning() << "Failed to load PCD file at" << path;
    }
}

void Visualizer::loadEmptyFrame(int index){
    pc_handler->startNewKeyframe(index);
    pc_handler->setActiveKeyframe(index);

    update();
}

void Visualizer::loadKeyframe(int oldIndex, int newIndex){
    pc_handler->setActiveKeyframe(newIndex);

    qDebug()<<"Load Keyframe " << oldIndex << ", " << newIndex;
    if(tabOpened == 1){
        if(oldIndex == -1) oldIndex = pc_handler->getCurrentKeyframeIndex();
        if(oldIndex!=newIndex){

            QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

            KeyframeVBO& highlightKf = keyframeVBOs[newIndex];
            KeyframeVBO& atOldKf = keyframeVBOs[oldIndex];

            int oldVertCount = pc_handler->getVertexCount(oldIndex);
            std::vector<GLubyte> oldColors;
            oldColors.resize(oldVertCount * 3);
            uint8_t gr, gg, gb;
            std::tie(gr, gg, gb) = getColorFromIndex(13);
            for (int i = 0; i < oldVertCount; i++) {
                oldColors[i*3 + 0] = gr;
                oldColors[i*3 + 1] = gg;
                oldColors[i*3 + 2] = gb;
            }

            if(atOldKf.colorBuffer) f->glDeleteBuffers(1, &atOldKf.colorBuffer);
            f->glGenBuffers(1, &atOldKf.colorBuffer);
            f->glBindBuffer(GL_ARRAY_BUFFER, atOldKf.colorBuffer);
            f->glBufferData(GL_ARRAY_BUFFER, oldColors.size() * sizeof(GLubyte), oldColors.data(), GL_STATIC_DRAW);

            int newVertCount = pc_handler->getVertexCount(newIndex);
            std::vector<GLubyte> newColors;
            newColors.resize(newVertCount * 3);
            uint8_t lr, lg, lb;
            std::tie(lr, lg, lb) = getColorFromIndex(1);
            for (int i = 0; i < newVertCount; i++) {
                newColors[i*3 + 0] = lr;
                newColors[i*3 + 1] = lg;
                newColors[i*3 + 2] = lb;
            }

            if(highlightKf.colorBuffer) f->glDeleteBuffers(1, &highlightKf.colorBuffer);
            f->glGenBuffers(1, &highlightKf.colorBuffer);
            f->glBindBuffer(GL_ARRAY_BUFFER, highlightKf.colorBuffer);
            f->glBufferData(GL_ARRAY_BUFFER, newColors.size() * sizeof(GLubyte), newColors.data(), GL_STATIC_DRAW);

        }
    }

    update();
}

void Visualizer::clearAllKeyframes(){
    pc_handler->clearAllKeyframes();

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

    for(const auto& vboStruct : keyframeVBOs){
        if(vboStruct.vbo){
            f->glDeleteBuffers(1, &vboStruct.vbo);
        }
        if(vboStruct.colorBuffer){
            f->glDeleteBuffers(1, &vboStruct.colorBuffer);
        }
    }
    keyframeVBOs.clear();

    qDebug() << "[Visualizer] Cleared All";


    update();  // Trigger redraw
}

void Visualizer::clearKeyframe(int index){
    if(pc_handler->clearKeyframe(index)){
        if (index >= 0 && index < keyframeVBOs.size()) {
            QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();

            if (keyframeVBOs[index].vbo) {
                f->glDeleteBuffers(1, &keyframeVBOs[index].vbo);
                keyframeVBOs[index].vbo = 0;
            }

            if (keyframeVBOs[index].colorBuffer) {
                f->glDeleteBuffers(1, &keyframeVBOs[index].colorBuffer);
                keyframeVBOs[index].colorBuffer = 0;
            }

            keyframeVBOs[index].vertexCount = 0;
        }
        update();  // Redraw to reflect changes
    }
}

void Visualizer::receiveScanSettings(quint8 eAngles, quint8 aAngles){
    l_eAngles = eAngles;
    l_aAngles = aAngles;
}

void Visualizer::changeActiveFrame(int af){
    activeFrameO = af;
}


void Visualizer::receiveLidarData(GLfloat d, GLfloat p, GLfloat t, int activeFrame, int sq){

    // if(activeFrameO!=-1)activeFrame = activeFrameO;

    static int tempActiveFrameNum = -1;
    int elev_pos = 0;
    int azim_pos = 0;
    if(activeFrame < 7){
        elev_pos = activeFrame;
        azim_pos = 0;
    }else if(activeFrame < 13){
        elev_pos = 13-activeFrame;
        azim_pos = 1;
    }else if(activeFrame < 19){
        elev_pos = activeFrame-12;
        azim_pos = 2;
    }else if(activeFrame < 25){
        elev_pos = 25-activeFrame;
        azim_pos = 3;
    }else if(activeFrame < 31){
        elev_pos = activeFrame-24;
        azim_pos = 4;
    }else if(activeFrame < 37){
        elev_pos = 37-activeFrame;
        azim_pos = 5;
    }else if(activeFrame < 43){
        elev_pos = activeFrame-36;
        azim_pos = 6;
    }else if(activeFrame < 49){
        elev_pos = 49-activeFrame;
        azim_pos = 7;
    }else if(activeFrame < 55){
        elev_pos = activeFrame-48;
        azim_pos = 8;
    }

    float m = COS_CORR, n=Y_OFFSET;
    float a = COS_CORR_PITCH;
    // float m = 0, n = 0;
    float correctionY = n + (m*0.14f)*(1-cos(p*(M_PI/180))) + (a*0.20f)*(1-cos(t*(M_PI/180)));

    float x = -d*cos(t*(M_PI/180))*sin(p*(M_PI/180));
    float y = -d*cos(t*(M_PI/180))+correctionY;
    float z = d*cos(p*(M_PI/180))*sin(t*(M_PI/180));


    //These are only estimates, SLAM will correct these values later on;
    float elev_angles[] = {0, 7.50, 15.00, 22.5, 30.00, 37.5, 45.00};
    float elev_angle = elev_angles[elev_pos];

    float azim_angles[] = {0,45.0,90.0,135.0,180.0,225.0,270.0,315.0,360};
    float azim_angle = azim_angles[azim_pos];

    qDebug() << x <<", " << y << ", " << z << ", " << p << ", " << t << ", " << d << ", " << activeFrame << ", " << sq;


    x=x/VERT_SCALE;
    y=y/VERT_SCALE;
    z=z/VERT_SCALE;

    qDebug() << x <<", " << y << ", " << z << ", " << p << ", " << t << ", " << d << ", " << activeFrame << ", " << sq;

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

    //Add Node Vertex Buffer
    if(activeFrame != tempActiveFrameNum){
        pc_handler->addNode(elev_angle, azim_angle, activeFrame);

        nodeVBOs.resize(activeFrame + 1);
        NodeVBO& nodeData = nodeVBOs[activeFrame];
        const GLfloat* nodevert = pc_handler->getNodeVertices(activeFrame);
        const GLubyte* color = pc_handler -> getNodeColor(activeFrame);

        Pose* newPose = pc_handler->getPoseData(activeFrame);
        updateNodeVBO(f, nodeData, nodevert, color, newPose);

        if(activeFrame != 0){
            Pose* prevPose = pc_handler->getPoseData(activeFrame-1);
            Eigen::Matrix4d rel = TransformHelper::computeRelativeFromEncoders(*prevPose, *newPose);
            Eigen::Matrix<double,6,6> info = Eigen::Matrix<double,6,6>::Identity() * 100;
            pc_handler->addEdge(activeFrame, activeFrame, rel, info);
        }

        tempActiveFrameNum = activeFrame;
    }

    if(d < 600){
        pc_handler->addLidarPoint(x,y,z,elev_angle, azim_angle, activeFrame);
    }

    if(activeFrame == pc_handler->getCurrentKeyframeIndex()){
        const GLfloat* vertices = pc_handler->getVertices(activeFrame);
        int vertexCount = pc_handler->getVertexCount();

        if (activeFrame >= static_cast<int>(keyframeVBOs.size())) {
            keyframeVBOs.resize(activeFrame + 1);
        }

        KeyframeVBO& vboData = keyframeVBOs[activeFrame];
        vboData.keyframeIndex = activeFrame;

        if (vboData.vbo) f->glDeleteBuffers(1, &vboData.vbo);
        f->glGenBuffers(1, &vboData.vbo);
        f->glBindBuffer(GL_ARRAY_BUFFER, vboData.vbo);
        f->glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);


        loadColor(activeFrame, vertexCount);
        vboData.vertexCount = vertexCount;
        update();
    }
}

void Visualizer::updateNodeVBO(QOpenGLFunctions* f, NodeVBO& vbo, const GLfloat* nodeVertices, const GLubyte* nodeColors, Pose* pose){

    // --- Point VBO (node position) ---
    if (vbo.vbo) f->glDeleteBuffers(1, &vbo.vbo);
    f->glGenBuffers(1, &vbo.vbo);
    f->glBindBuffer(GL_ARRAY_BUFFER, vbo.vbo);
    f->glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(GLfloat), nodeVertices, GL_STATIC_DRAW);

    if (vbo.colorBuffer) f->glDeleteBuffers(1, &vbo.colorBuffer);
    f->glGenBuffers(1, &vbo.colorBuffer);
    f->glBindBuffer(GL_ARRAY_BUFFER, vbo.colorBuffer);
    f->glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(GLubyte), nodeColors, GL_STATIC_DRAW);

    vbo.vertexCount = 1;

    // --- Axis VBO (orientation lines) ---
    float axisLength = 0.5f;

    double yawDeg = pose->yaw;
    double pitchDeg = pose->pitch;

    double yawRad = yawDeg * M_PI / 180.0;
    double pitchRad = pitchDeg * M_PI / 180.0;

    QMatrix4x4 R;
    R.setToIdentity();
    R.rotate(-90,1,0,0);
    R.rotate(90,0,1,0);
    R.rotate(-yawDeg, 1, 0, 0);   // yaw around Y
    R.rotate(pitchDeg, 0, 0, 1); // pitch around X*/


    QVector3D origin(nodeVertices[0], nodeVertices[1], nodeVertices[2]);

    QVector3D xEnd = origin + R.mapVector(QVector3D(axisLength, 0, 0));
    QVector3D yEnd = origin + R.mapVector(QVector3D(0, axisLength, 0));
    QVector3D zEnd = origin + R.mapVector(QVector3D(0, 0, axisLength));

    GLfloat axisVertices[] = {
        origin.x(), origin.y(), origin.z(), xEnd.x(), xEnd.y(), xEnd.z(), // X-axis
        origin.x(), origin.y(), origin.z(), yEnd.x(), yEnd.y(), yEnd.z(), // Y-axis
        origin.x(), origin.y(), origin.z(), zEnd.x(), zEnd.y(), zEnd.z()  // Z-axis
    };

    GLubyte axisColors[] = {
        255, 0, 0,   255, 0, 0,   // X-axis (red)
        0, 255, 0,   0, 255, 0,   // Y-axis (green)
        0, 0, 255,   0, 0, 255    // Z-axis (blue)
    };

    // --- Upload axis VBO ---
    if (!vbo.axisVBO) f->glGenBuffers(1, &vbo.axisVBO);
    f->glBindBuffer(GL_ARRAY_BUFFER, vbo.axisVBO);
    f->glBufferData(GL_ARRAY_BUFFER, sizeof(axisVertices), axisVertices, GL_STATIC_DRAW);

    if (!vbo.axisColorBuffer) f->glGenBuffers(1, &vbo.axisColorBuffer);
    f->glBindBuffer(GL_ARRAY_BUFFER, vbo.axisColorBuffer);
    f->glBufferData(GL_ARRAY_BUFFER, sizeof(axisColors), axisColors, GL_STATIC_DRAW);

    vbo.axisVertexCount = 6; // 3 lines * 2 vertices
}

void Visualizer::registerKeyframe() {
    int ref = 0, curr = 1;
    pc_handler->registerKeyframe(ref, curr);
    int index = pc_handler->getCurrentKeyframeIndex();

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

    // Clean up old VBO if exists
    if (index < keyframeVBOs.size()) {
        if (keyframeVBOs[index].vbo)
            f->glDeleteBuffers(1, &keyframeVBOs[index].vbo);
        if (keyframeVBOs[index].colorBuffer)
            f->glDeleteBuffers(1, &keyframeVBOs[index].colorBuffer);
    } else {
        keyframeVBOs.resize(index + 1);
    }

    // Create new VBOs for aligned cloud
    GLuint vbo, colorBuffer;
    f->glGenBuffers(1, &vbo);
    f->glBindBuffer(GL_ARRAY_BUFFER, vbo);
    f->glBufferData(GL_ARRAY_BUFFER,
                    pc_handler->getVertexCount() * 3 * sizeof(GLfloat),
                    pc_handler->getVertices(index),
                    GL_STATIC_DRAW);

    f->glGenBuffers(1, &colorBuffer);
    f->glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    f->glBufferData(GL_ARRAY_BUFFER,
                    pc_handler->getVertexCount() * 3 * sizeof(GLubyte),
                    pc_handler->getColors(index),
                    GL_STATIC_DRAW);

    keyframeVBOs[index] = {
        vbo,
        colorBuffer,
        pc_handler->getVertexCount(),
        true
    };

    qDebug() << "[Visualizer] Updated Keyframe VBO #" << index;

    update(); // Trigger repaint
}

void Visualizer::constructMesh(){
    pc_handler->reconstructSurface();

    update();
}

void Visualizer::setKeyframeVisible(int idx, bool visible){
    if (idx >= 0 && idx < static_cast<int>(keyframeVBOs.size())) {
        qDebug() << idx;
        keyframeVBOs[idx].visible = visible;
        update(); // trigger redraw
    }
}

void Visualizer::handlePosUpdate(int index){

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

    const GLfloat* vertices = pc_handler->getVertices(index);
    int vertexCount = pc_handler->getVertexCount();

    KeyframeVBO& vboData = keyframeVBOs[index];

    if (vboData.vbo) f->glDeleteBuffers(1, &vboData.vbo);
    f->glGenBuffers(1, &vboData.vbo);
    f->glBindBuffer(GL_ARRAY_BUFFER, vboData.vbo);
    f->glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

    vboData.vertexCount = vertexCount;
    update();
}

void Visualizer::updateByLoadSession(int kfCount){

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

    keyframeVBOs.resize(kfCount);

    for(int i = 0; i < keyframeVBOs.size(); i++){

        pc_handler->setActiveKeyframe(i);
        int v = pc_handler->getVertexCount(i);
        const GLfloat* vertices = pc_handler->getVertices(i);
        int vertexCount = pc_handler->getVertexCount();

        KeyframeVBO& vboData = keyframeVBOs[i];
        vboData.visible = true;

        if (vboData.vbo) f->glDeleteBuffers(1, &vboData.vbo);
        f->glGenBuffers(1, &vboData.vbo);
        f->glBindBuffer(GL_ARRAY_BUFFER, vboData.vbo);
        f->glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

        loadColor(i,v);
        vboData.vertexCount = v;
    }

    update();
}

void Visualizer::loadColor(int index, int vertCount){

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

    if(tabOpened == 0){
        KeyframeVBO& vboData = keyframeVBOs[index];
        const GLubyte* colors = pc_handler->getColors(index);
        if (vboData.colorBuffer) f->glDeleteBuffers(1, &vboData.colorBuffer);
        f->glGenBuffers(1, &vboData.colorBuffer);
        f->glBindBuffer(GL_ARRAY_BUFFER, vboData.colorBuffer);
        f->glBufferData(GL_ARRAY_BUFFER, vertCount * 3 * sizeof(GLubyte), colors, GL_STATIC_DRAW);
    }else if(tabOpened == 1){
        // 🧠 Upload using QOpenGLFunctions
        uint8_t gr, gg, gb;
        std::tie(gr, gg, gb) = getColorFromIndex(13);
        uint8_t lr, lg, lb;
        std::tie(lr, lg, lb) = getColorFromIndex(1);


        for(int i = 0; i < keyframeVBOs.size(); i++){
            int kfVertCount = pc_handler->getVertexCount(i);
            KeyframeVBO& kf = keyframeVBOs[i];
            // VBO for colors
            std::vector<GLubyte> colors;
            colors.resize(kfVertCount * 3);

            if(index != i){
                for (int i = 0; i < kfVertCount; i++) {
                    colors[i*3 + 0] = gr;
                    colors[i*3 + 1] = gg;
                    colors[i*3 + 2] = gb;
                }
            }else{
                for (int i = 0; i < kfVertCount; i++) {
                    colors[i*3 + 0] = lr;
                    colors[i*3 + 1] = lg;
                    colors[i*3 + 2] = lb;
                }
            }

            if (kf.colorBuffer) {
                f->glDeleteBuffers(1, &kf.colorBuffer);
            }
            f->glGenBuffers(1, &kf.colorBuffer);
            f->glBindBuffer(GL_ARRAY_BUFFER, kf.colorBuffer);
            f->glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(GLubyte), colors.data(), GL_STATIC_DRAW);
        }
    }
}

void Visualizer::updateCurrentTab(int index) {
    tabOpened = index;
    QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();

    if(index == 0){
        for(int i = 0; i < keyframeVBOs.size(); i++){
            const GLubyte* colors = pc_handler->getColors(i);
            KeyframeVBO& kf = keyframeVBOs[i];
            int vertexCount = pc_handler->getVertexCount(i);

            if (kf.colorBuffer) {
                f->glDeleteBuffers(1, &kf.colorBuffer);
            }
            f->glGenBuffers(1, &kf.colorBuffer);
            f->glBindBuffer(GL_ARRAY_BUFFER, kf.colorBuffer);
            f->glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(GLubyte), colors, GL_STATIC_DRAW);
        }
    }
    else if(index == 1){
        int currIndex = pc_handler->getCurrentKeyframeIndex();

        // 🧠 Upload using QOpenGLFunctions
        uint8_t gr, gg, gb;
        std::tie(gr, gg, gb) = getColorFromIndex(13);
        uint8_t lr, lg, lb;
        std::tie(lr, lg, lb) = getColorFromIndex(1);


        for(int i = 0; i < keyframeVBOs.size(); i++){
            int kfVertCount = pc_handler->getVertexCount(i);
            KeyframeVBO& kf = keyframeVBOs[i];
            // VBO for colors
            std::vector<GLubyte> colors;
            colors.resize(kfVertCount * 3);

            if(currIndex != i){
                for (int i = 0; i < kfVertCount; i++) {
                    colors[i*3 + 0] = gr;
                    colors[i*3 + 1] = gg;
                    colors[i*3 + 2] = gb;
                }
            }else{
                for (int i = 0; i < kfVertCount; i++) {
                    colors[i*3 + 0] = lr;
                    colors[i*3 + 1] = lg;
                    colors[i*3 + 2] = lb;
                }
            }

            if (kf.colorBuffer) {
                f->glDeleteBuffers(1, &kf.colorBuffer);
            }
            f->glGenBuffers(1, &kf.colorBuffer);
            f->glBindBuffer(GL_ARRAY_BUFFER, kf.colorBuffer);
            f->glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(GLubyte), colors.data(), GL_STATIC_DRAW);
        }

    }
    else if (index == 2){
        // 🧠 Upload using QOpenGLFunctions
        uint8_t gr, gg, gb; // Grey
        std::tie(gr, gg, gb) = getColorFromIndex(13);
        uint8_t sr, sg, sb; // Green
        std::tie(sr, sg, sb) = getColorFromIndex(1);
        uint8_t tr, tg, tb; // Red
        std::tie(tr, tg, tb) = getColorFromIndex(0);

        uint8_t cr,cg,cb;

        for(int i = 0; i < keyframeVBOs.size(); i++){
            int kfVertCount = pc_handler->getVertexCount(i);
            KeyframeVBO& kf = keyframeVBOs[i];
            // VBO for colors
            std::vector<GLubyte> colors;
            colors.resize(kfVertCount * 3);

            if(i == targetIndex){
                cr = tr;
                cg = tg;
                cb = tb;
            }else if (i == sourceIndex){
                cr = sr;
                cg = sg;
                cb = sb;
            }else{
                cr = gr;
                cg = gg;
                cb = gb;
            }

            for (int i = 0; i < kfVertCount; i++) {
                colors[i*3 + 0] = cr;
                colors[i*3 + 1] = cg;
                colors[i*3 + 2] = cb;
            }

            if (kf.colorBuffer) {
                f->glDeleteBuffers(1, &kf.colorBuffer);
            }
            f->glGenBuffers(1, &kf.colorBuffer);
            f->glBindBuffer(GL_ARRAY_BUFFER, kf.colorBuffer);
            f->glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(GLubyte), colors.data(), GL_STATIC_DRAW);
        }
    }
    else if (index == 3) {
        pc_handler->combineKeyframes();

        // 🟢 Get combined cloud
        pcl::PointCloud<pcl::PointXYZRGB>::Ptr combined = pc_handler->getCombinedKeyframe();
        int vertexCount = static_cast<int>(combined->points.size());

        // 🔄 Convert to flat buffers
        std::vector<GLfloat> vertices;
        std::vector<GLubyte> colors;
        vertices.reserve(vertexCount * 3);
        colors.reserve(vertexCount * 3);

        for (const auto& pt : combined->points) {
            vertices.push_back(pt.x);
            vertices.push_back(pt.y);
            vertices.push_back(pt.z);

            colors.push_back(pt.r);
            colors.push_back(pt.g);
            colors.push_back(pt.b);
        }

        // 🧠 Upload using QOpenGLFunctions
        QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();

        // VBO for positions
        if (combinedVBO.vbo) {
            f->glDeleteBuffers(1, &combinedVBO.vbo);
        }
        f->glGenBuffers(1, &combinedVBO.vbo);
        f->glBindBuffer(GL_ARRAY_BUFFER, combinedVBO.vbo);
        f->glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

        // VBO for colors
        if (combinedVBO.colorBuffer) {
            f->glDeleteBuffers(1, &combinedVBO.colorBuffer);
        }
        f->glGenBuffers(1, &combinedVBO.colorBuffer);
        f->glBindBuffer(GL_ARRAY_BUFFER, combinedVBO.colorBuffer);
        f->glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(GLubyte), colors.data(), GL_STATIC_DRAW);

        combinedVBO.vertexCount = vertexCount;
    }

    update(); // trigger redraw
}

void Visualizer::changeTargetIndex(int ti){
    targetIndex = ti;
    if(tabOpened == 2){
        updateCurrentTab(2);
    }
}

void Visualizer::changeSourceIndex(int si){
    sourceIndex = si;
    if(tabOpened == 2){
        updateCurrentTab(2);
    }
}

void Visualizer::initializeGL(){
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glPointSize(8);
    glEnable(GL_POINT_SMOOTH);

    panOffset = QVector3D(0.0f, 0.0f, 0.0f);

    bool success;
    success = shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vis_vert.glsl");
    success = shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/vis_frag.glsl");

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_data), triangle_data, GL_STATIC_DRAW);

    glGenBuffers(1, &colorbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);

    shaderProgram.link();

    GLuint programID = shaderProgram.programId();
    MVP_ID = glGetUniformLocation(programID, "MVP");

    projection.perspective(30.0, 3.0/3.0, 0.001f, 100.0f);

    view.setToIdentity();
    view.lookAt(QVector3D(5,3,5),
                QVector3D(0,1,0),
                QVector3D(0,1,0));

    model.setToIdentity();
    MVP = projection * view * model;

    vertexPosition_modelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");
    colorlocation = glGetAttribLocation(programID, "v_color");

    //Grid Setup

    bool grid_s;
    grid_s = gridProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/grid_vert.glsl");
    grid_s = gridProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/grid_frag.glsl");

    Gridvertices grid_verts(1.0f,20);
    const GLfloat* vertices = grid_verts.getVertices();
    int vertCount = grid_verts.getVertexCount();

    glGenBuffers(1, &gridbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, gridbuffer);
    glBufferData(GL_ARRAY_BUFFER, vertCount * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

    gridProgram.link();
    GLuint gridID = gridProgram.programId();
    MVP_GRID_ID = glGetUniformLocation(gridID, "MVP");
    gridPosition_modelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");
    MVP_grid = MVP;

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void Visualizer::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // === Activate main shader ===
    shaderProgram.bind();
    GLuint programID = shaderProgram.programId();
    glUseProgram(programID);

    // === Camera & MVP matrix ===
    float radYaw = -qDegreesToRadians(yaw);
    float radPitch = qDegreesToRadians(pitch);
    float x = radius * qCos(radPitch) * qSin(radYaw);
    float y = radius * qSin(radPitch);
    float z = radius * qCos(radPitch) * qCos(radYaw);
    cameraPos = QVector3D(x, y, z);

    view.setToIdentity();
    view.lookAt(cameraPos + panOffset, target + panOffset, QVector3D(0, 1, 0));
    // view.translate(panOffset.x(), panOffset.y(), panOffset.z());

    QMatrix4x4 MVP = projection * view * model;
    glUniformMatrix4fv(MVP_ID, 1, GL_FALSE, MVP.constData());
    MVP_grid = MVP;

    QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();

    // === Draw PCD Points (if loaded) ===

    if(tabOpened == 0 || tabOpened == 4){
        if(keyframeVBOs.size() > 0){
            int t = pc_handler->getCurrentKeyframeIndex();
            auto cloud = pc_handler->getCurrentKeyframe();
            // qDebug() << "Big Size..";
            if(cloud && !cloud->empty() && keyframeVBOs[t].visible){
                f->glBindBuffer(GL_ARRAY_BUFFER, keyframeVBOs[t].vbo);
                f->glVertexAttribPointer(vertexPosition_modelspaceID, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
                f->glEnableVertexAttribArray(vertexPosition_modelspaceID);

                f->glBindBuffer(GL_ARRAY_BUFFER, keyframeVBOs[t].colorBuffer);
                f->glVertexAttribPointer(colorlocation, 3, GL_UNSIGNED_BYTE, GL_TRUE, 0, nullptr);
                f->glEnableVertexAttribArray(colorlocation);

                f->glDrawArrays(GL_POINTS, 0, keyframeVBOs[t].vertexCount);
            }

            if(nodeVBOs.size() != 0){
                if (nodeVBOs[t].vbo && nodeVBOs[t].colorBuffer && nodeVBOs[t].visible) {
                    // Bind node position
                    f->glBindBuffer(GL_ARRAY_BUFFER, nodeVBOs[t].vbo);
                    f->glVertexAttribPointer(vertexPosition_modelspaceID, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
                    f->glEnableVertexAttribArray(vertexPosition_modelspaceID);

                    // Bind node color
                    f->glBindBuffer(GL_ARRAY_BUFFER, nodeVBOs[t].colorBuffer);
                    f->glVertexAttribPointer(colorlocation, 3, GL_UNSIGNED_BYTE, GL_TRUE, 0, nullptr);
                    f->glEnableVertexAttribArray(colorlocation);

                    // Draw exactly 1 vertex
                    f->glDrawArrays(GL_POINTS, 0, 1);
                }

                // --- Draw Pose Axis ---
                if (nodeVBOs[t].axisVBO && nodeVBOs[t].axisColorBuffer && nodeVBOs[t].visible) {
                    // Axis positions
                    f->glBindBuffer(GL_ARRAY_BUFFER, nodeVBOs[t].axisVBO);
                    f->glVertexAttribPointer(vertexPosition_modelspaceID, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
                    f->glEnableVertexAttribArray(vertexPosition_modelspaceID);

                    // Axis colors
                    f->glBindBuffer(GL_ARRAY_BUFFER, nodeVBOs[t].axisColorBuffer);
                    f->glVertexAttribPointer(colorlocation, 3, GL_UNSIGNED_BYTE, GL_TRUE, 0, nullptr);
                    f->glEnableVertexAttribArray(colorlocation);

                    // Draw 3 lines = 6 vertices
                    f->glDrawArrays(GL_LINES, 0, nodeVBOs[t].axisVertexCount);
                }
            }
        }
    }else if(tabOpened == 1){
        for (const KeyframeVBO& vbo : keyframeVBOs) {
            if (!vbo.visible || vbo.vertexCount == 0 || !vbo.visible) continue;

            f->glBindBuffer(GL_ARRAY_BUFFER, vbo.vbo);
            f->glVertexAttribPointer(vertexPosition_modelspaceID, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
            f->glEnableVertexAttribArray(vertexPosition_modelspaceID);

            f->glBindBuffer(GL_ARRAY_BUFFER, vbo.colorBuffer);
            f->glVertexAttribPointer(colorlocation, 3, GL_UNSIGNED_BYTE, GL_TRUE, 0, nullptr);
            f->glEnableVertexAttribArray(colorlocation);

            f->glDrawArrays(GL_POINTS, 0, vbo.vertexCount);
        }

        for (const NodeVBO& vbo : nodeVBOs){
            // Bind node position
            f->glBindBuffer(GL_ARRAY_BUFFER, vbo.vbo);
            f->glVertexAttribPointer(vertexPosition_modelspaceID, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
            f->glEnableVertexAttribArray(vertexPosition_modelspaceID);

            // Bind node color
            f->glBindBuffer(GL_ARRAY_BUFFER, vbo.colorBuffer);
            f->glVertexAttribPointer(colorlocation, 3, GL_UNSIGNED_BYTE, GL_TRUE, 0, nullptr);
            f->glEnableVertexAttribArray(colorlocation);

            // Draw exactly 1 vertex
            f->glDrawArrays(GL_POINTS, 0, 1);

        }
    }else if (tabOpened == 2 || tabOpened == 3){
        f->glBindBuffer(GL_ARRAY_BUFFER, combinedVBO.vbo);
        f->glVertexAttribPointer(vertexPosition_modelspaceID, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        f->glEnableVertexAttribArray(vertexPosition_modelspaceID);

        f->glBindBuffer(GL_ARRAY_BUFFER, combinedVBO.colorBuffer);
        f->glVertexAttribPointer(colorlocation, 3, GL_UNSIGNED_BYTE, GL_TRUE, 0, nullptr);
        f->glEnableVertexAttribArray(colorlocation);

        f->glDrawArrays(GL_POINTS, 0, combinedVBO.vertexCount);
    }else if(tabOpened == 3){
        const std::vector<float>& vertices = pc_handler->getMeshVertices();
        const std::vector<unsigned int>& indices = pc_handler->getMeshIndices();

        if (!vertices.empty() && !indices.empty()) {
            GLuint meshVBO, meshIBO;

            f->glGenBuffers(1, &meshVBO);
            f->glBindBuffer(GL_ARRAY_BUFFER, meshVBO);
            f->glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

            f->glVertexAttribPointer(vertexPosition_modelspaceID, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
            f->glEnableVertexAttribArray(vertexPosition_modelspaceID);

            f->glGenBuffers(1, &meshIBO);
            f->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, meshIBO);
            f->glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

            f->glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);

            // Optional: Cleanup temporary buffers if not persistent
            f->glDeleteBuffers(1, &meshVBO);
            f->glDeleteBuffers(1, &meshIBO);
        }
    }

    shaderProgram.release();

    // === Draw Grid ===
    gridProgram.bind();
    glUniformMatrix4fv(MVP_GRID_ID, 1, GL_FALSE, MVP_grid.constData());

    glBindBuffer(GL_ARRAY_BUFFER, gridbuffer);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glDrawArrays(GL_LINES, 0, 300);

    glDisableVertexAttribArray(0);
    gridProgram.release();
}

void Visualizer::triggerKeyframeChange(int index){
    QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();

    if(index == pc_handler->getCurrentKeyframeIndex()){
        const GLfloat* vertices = pc_handler->getVertices(index);
        const GLubyte* colors = pc_handler->getColors(index);
        int vertexCount = pc_handler->getVertexCount();

        KeyframeVBO& vboData = keyframeVBOs[index];

        if (vboData.vbo) f->glDeleteBuffers(1, &vboData.vbo);
        f->glGenBuffers(1, &vboData.vbo);
        f->glBindBuffer(GL_ARRAY_BUFFER, vboData.vbo);
        f->glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

        if (vboData.colorBuffer) f->glDeleteBuffers(1, &vboData.colorBuffer);
        f->glGenBuffers(1, &vboData.colorBuffer);
        f->glBindBuffer(GL_ARRAY_BUFFER, vboData.colorBuffer);
        f->glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(GLubyte), colors, GL_STATIC_DRAW);

        // qDebug() << "[Visualizer] Loaded PCD with" << pc_handler->getVertexCount() << "points.";

        vboData.vertexCount = vertexCount;
        update();
    }
}

void Visualizer::triggerUpdate(){

    // 🟢 Get combined cloud
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr combined = pc_handler->getCombinedKeyframe();
    int vertexCount = static_cast<int>(combined->points.size());

    qDebug() << "Updating with " << QString::number(vertexCount) << " vertices";

    // 🔄 Convert to flat buffers
    std::vector<GLfloat> vertices;
    std::vector<GLubyte> colors;
    vertices.reserve(vertexCount * 3);
    colors.reserve(vertexCount * 3);

    for (const auto& pt : combined->points) {
        vertices.push_back(pt.x);
        vertices.push_back(pt.y);
        vertices.push_back(pt.z);

        colors.push_back(pt.r);
        colors.push_back(pt.g);
        colors.push_back(pt.b);
    }

    // 🧠 Upload using QOpenGLFunctions
    QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();

    // VBO for positions
    if (combinedVBO.vbo) {
        f->glDeleteBuffers(1, &combinedVBO.vbo);
    }
    f->glGenBuffers(1, &combinedVBO.vbo);
    f->glBindBuffer(GL_ARRAY_BUFFER, combinedVBO.vbo);
    f->glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

    // VBO for colors
    if (combinedVBO.colorBuffer) {
        f->glDeleteBuffers(1, &combinedVBO.colorBuffer);
    }
    f->glGenBuffers(1, &combinedVBO.colorBuffer);
    f->glBindBuffer(GL_ARRAY_BUFFER, combinedVBO.colorBuffer);
    f->glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(GLubyte), colors.data(), GL_STATIC_DRAW);

    combinedVBO.vertexCount = vertexCount;
    update();
}

void Visualizer::visRegisterKeyframe(int sourceIndex, int targetIndex, RegistrationResult res){
    qDebug() << res.fitness_score << " " << res.success;
}

void Visualizer::changeRot(int rot){
    if(rot == 0)
        automatic = false;
    else{
        automatic = true;
        rotVal = 0.15;
    }
}

void Visualizer::updateRot(bool dir){
    if(!dir){
        rotating = true;
        yaw-=1;
    }
    else{
        rotating = true;
        yaw+=1;
    }
}

void Visualizer::stopRot(){
    rotating = false;
}

void Visualizer::mousePressEvent(QMouseEvent *event){
    setFocus();
    if (event->button() == Qt::LeftButton) {
        lastMousePos = event->pos();
        m_rotating = true;
    }if (event->button() == Qt::RightButton) {
        m_panning = true;
        lastMousePos = event->pos();
    }else{
        // qDebug() << event->button();
    }
}

void Visualizer::mouseMoveEvent(QMouseEvent *event){
    if (m_rotating & !m_panning) {
        QPoint delta = event->pos() - lastMousePos;
        lastMousePos = event->pos();

        float sensitivity = 0.2;
        yaw += delta.x() * sensitivity;
        pitch += delta.y() * sensitivity;

        pitch = std::clamp(pitch, -89.0f, 89.0f);

        update();
    }else if (m_panning & !m_rotating) {
        QPoint delta = event->pos() - lastMousePos;
        lastMousePos = event->pos();

        float scale = 0.001f*radius;

        // 1. Get camera direction vectors
        QVector3D forward = (target - cameraPos).normalized();

        // Cross product to get right & up
        QVector3D right = QVector3D::crossProduct(forward, QVector3D(0,1,0)).normalized();
        QVector3D up = QVector3D::crossProduct(right, forward).normalized();

        // 2. Apply delta to pan in view space
        panOffset -= right * delta.x() * scale;
        panOffset += up * delta.y() * scale;

        update();
    }
}

void Visualizer::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
        m_rotating = false;
    }else if(event->button() == Qt::RightButton){
        m_panning = false;
    }
}

void Visualizer::wheelEvent(QWheelEvent *event) {
    setFocus();
    float zoomSpeed = radius*0.2f;

    // delta is in 1/8 degrees, so divide by 120 to normalize to ±1 per notch
    int numDegrees = event->angleDelta().y() / 120;
    radius -= numDegrees * zoomSpeed;

    // Clamp to prevent flipping or clipping
    radius = std::clamp(radius, 0.01f, 100.0f);

    update(); // Trigger redraw
}

void Visualizer::keyPressEvent(QKeyEvent *event) {
    float step = radius/100.0f;

    QVector3D viewDir = (target - cameraPos).normalized();
    QVector3D right = QVector3D::crossProduct(viewDir, QVector3D(0, 1, 0)).normalized();

    if (event->key() == Qt::Key_Up) {
        target += QVector3D(0, step, 0);
    } else if (event->key() == Qt::Key_Down) {
        target -= QVector3D(0, step, 0);
    } else if (event->key() == Qt::Key_Right) {
        target += right * step;
    } else if (event->key() == Qt::Key_Left) {
        target -= right * step;
    }

    update(); // trigger repaint
}


void Visualizer::timerEvent(QTimerEvent*){
    if((automatic || rotating) && !m_rotating){
        if(rotating)
            yaw += 1.0f;
        else
            yaw += 0.1f;

        update();
    }
}

void Visualizer::resizeGL(int w, int h){
    Q_UNUSED(w);
    Q_UNUSED(h);
}
