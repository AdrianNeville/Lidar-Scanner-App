#ifndef VISUALIZER_H
#define VISUALIZER_H

#include "pointcloudhandler.h"
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QtOpenGL/QOpenGLFunctions_3_3_Core>
#include <QExposeEvent>
#include <QOpenGLShaderProgram>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

struct KeyframeVBO {
    GLuint vbo = 0;
    GLuint colorBuffer = 0;
    int vertexCount = 0;
    bool visible = true;
    int keyframeIndex;
};

struct NodeVBO {
    GLuint vbo = 0;
    GLuint colorBuffer = 0;
    int vertexCount = 0;

    // Pose axes
    GLuint axisVBO = 0;
    GLuint axisColorBuffer = 0;
    int axisVertexCount = 6; // 3 lines

    bool visible = true;
};


class Visualizer : public QOpenGLWidget, public QOpenGLFunctions_3_3_Core
{
    Q_OBJECT
public:
    Visualizer(QWidget *parent = nullptr);
    ~Visualizer();

    void setKeyframeVisible(int idx, bool visible);
    PointCloudHandler* getPointCloudHandler() const { return pc_handler; }
    void changeTargetIndex(int ti);
    void changeSourceIndex(int si);
    void changeActiveFrame(int af);
public slots:
    void changeRot(int rot);
    void updateRot(bool dir);
    void stopRot();
    void receiveLidarData(GLfloat d, GLfloat r, GLfloat s, int activeFrame, int sq);
    void loadPCD(const QString& path);
    void loadKeyframe(int oldIndex, int newIndex);
    void clearKeyframe(int KFNum);
    void clearAllKeyframes();
    void registerKeyframe();
    void constructMesh();
    void updateCurrentTab(int index);
    void loadEmptyFrame(int index);
    void receiveScanSettings(quint8 eAngles, quint8 aAngles);
    void triggerUpdate();
    void triggerKeyframeChange(int index);
    void handlePosUpdate(int index);

    void visRegisterKeyframe(int sourceIndex, int targetIndex, RegistrationResult res);
    void updateByLoadSession(int kfCount);
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
    void timerEvent(QTimerEvent*) override;

    //Camera Control
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
private:
    int prevSize = 0;
    int newSize = 0;

    quint8 l_eAngles = 1;
    quint8 l_aAngles = 1;

    bool rotating = false;
    bool automatic = false;
    float rotVal = 0.15f;
    float scale = 0.01f;

    QOpenGLShaderProgram shaderProgram;
    GLuint MVP_ID;
    GLuint vertexPosition_modelspaceID;
    GLuint VBO;
    GLuint colorlocation;
    GLuint colorbuffer;

    QOpenGLShaderProgram gridProgram;
    GLuint MVP_GRID_ID;
    GLuint gridPosition_modelspaceID;
    GLuint gridbuffer;
    GLuint gridcolorbuffer;

    unsigned int verts;
    QMatrix4x4 MVP;
    QMatrix4x4 MVP_grid;

    QMatrix4x4 model;
    QMatrix4x4 view;
    QMatrix4x4 projection;

    float yaw = 0.0f;     // Horizontal angle (around Y-axis)
    float pitch = 15.0f;   // Vertical angle (around X-axis)
    float radius = 10.0f; // Distance from the center

    QVector3D target;
    QVector3D cameraPos;
    float targetY = 0.1f;

    QPoint lastMousePos;
    bool m_rotating = false;
    bool m_panning = false;
    float angleX = 0.0f;
    float angleY = 0.0f;
    QVector3D panOffset;


    PointCloudHandler* pc_handler;

    std::vector<KeyframeVBO> keyframeVBOs;
    std::vector<NodeVBO> nodeVBOs;
    KeyframeVBO combinedVBO;
    GLuint pcdVBO = 0;
    GLuint pcdColorBuffer = 0;
    int pcdVertexCount = 0;

    int tabOpened = 0;
    void loadVertices();
    void loadColor(int index, int vertCount);

    int targetIndex = -1;
    int sourceIndex = -1;
    int activeFrameO = -1;

    void updateNodeVBO(QOpenGLFunctions* f, NodeVBO& vbo, const GLfloat* nodeVertices, const GLubyte* nodeColors, Pose* pose);
};

#endif
