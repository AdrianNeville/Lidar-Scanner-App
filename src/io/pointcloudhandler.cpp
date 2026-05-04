#include "PointCloudHandler.h"
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <boost/make_shared.hpp>
#include <QFileInfo>
#include <QFileDialog>
#include <QDebug>
#include <pcl/common/transforms.h>   // For pcl::transformPointCloud
#include <Eigen/Dense>

#include <pcl/registration/sample_consensus_prerejective.h>
#include <pcl/registration/icp.h>
#include <pcl/features/fpfh.h>
#include <pcl/features/normal_3d.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/common/transforms.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/surface/mls.h>
#include <pcl/search/kdtree.h>

#include <pcl/io/pcd_io.h>
#include <QDir>

#include <pcl/surface/marching_cubes_rbf.h>
#include <pcl/surface/poisson.h>
#include <pcl/PolygonMesh.h>
#include <pcl/common/transforms.h>

#include "colorutils.h"
#include "utils/position_utils.h"
#include "types/position.h"
#include "helpers/PointCloudIO.h"

#include <pcl/filters/passthrough.h>

PointCloudHandler::PointCloudHandler(QObject* parent) : QObject(parent){
    qDebug() << "New Handler";
}

bool PointCloudHandler::loadFromFile(const QString& path, int index) {
    bool hasColor = false;
    auto cloud = PointCloudIO::loadFromFile(path,hasColor);

    if (!cloud) return false;
    if (index < 0 || index >= static_cast<int>(keyframes.size())) return false;

    keyframes[index].cloud = cloud;
    keyframes[index].originalCloud = std::make_shared<CloudT>(*cloud);
    qDebug() << "[INFO] Loaded keyframe" << index << "with" << cloud->size() << "points";
    return true;
}

void PointCloudHandler::addLidarPoint(float x, float y, float z, double elev, double azim, int keyframeIndex) {
    if (currentKeyframeIndex < 0 || currentKeyframeIndex > keyframes.size()) return;

    uint8_t r, g, b;
    std::tie(r, g, b) = getColorFromIndex(keyframeIndex);

    pcl::PointXYZRGB pt;
    pt.x = x;
    pt.y = y;
    pt.z = z;
    pt.r = r;
    pt.g = g;
    pt.b = b;
    pcl::PointXYZRGB pt_transformed = pt;

    auto& kfo = keyframes[keyframeIndex].originalCloud;
    kfo->points.push_back(pt);
    kfo->width = static_cast<uint32_t>(kfo->points.size());
    kfo->height = 1;
    kfo->is_dense = false;

    Eigen::Affine3f tf_pos = poseToTransform(keyframes[keyframeIndex].pos);
    Eigen::Vector3f p(pt.x, pt.y, pt.z);
    Eigen::Vector3f p_tf = tf_pos * p;
    pt_transformed.x = p_tf.x();
    pt_transformed.y = p_tf.y();
    pt_transformed.z = p_tf.z();

    auto& kf = keyframes[keyframeIndex];
    kf.cloud->points.push_back(pt_transformed);
    kf.cloud->width = static_cast<uint32_t>(kf.cloud->points.size());
    kf.cloud->height = 1;
    kf.cloud->is_dense = false;
}

void PointCloudHandler::addNode(double elev, double azim, int index){
    auto& ktemp = keyframes[index];
    ktemp.pos.pitch = elev;
    ktemp.pos.yaw = azim;
    ktemp.nodeId = index;

    Pose pose(elev,azim);
    Node tNode;
    tNode.pose = pose;
    tNode.id = index;
    ktemp.nodeId = index;

    poseGraph.nodes[index] = tNode;
}

void PointCloudHandler::addEdge(int from, int to,
                                const Eigen::Matrix4d& rel_pose,
                                const Eigen::Matrix<double,6,6>& info){
    Edge e;
    e.from = from;
    e.to = to;
    e.relative_pose = rel_pose;
    e.information = info;
    poseGraph.edges.push_back(e);
}

Pose* PointCloudHandler::getPoseData(int index){
    return &poseGraph.nodes[index].pose;
}

std::array<double, 6> PointCloudHandler::getPosData(int index){
    std::array<double, 6> arr{};

    if (index < 0 || index >= static_cast<int>(keyframes.size())) {
        qDebug() << "Index out of bounds in getPoseData";
        return arr; // all zeros
    }

    const Position& p = keyframes[index].pos;
    arr[0] = p.x;
    arr[1] = p.y;
    arr[2] = p.z;
    arr[3] = p.roll;
    arr[4] = p.pitch;
    arr[5] = p.yaw;

    qDebug() << "Obtained pose:" << p.x;

    return arr;
}

void PointCloudHandler::loadPointsfromSession(int kfCount){
    emit PointCloudHandler::updateByLoadSession(kfCount);
    emit PointCloudHandler::updateComboCount(kfCount);
}

void PointCloudHandler::setPosData(int index){
    if (index < 0 || index >= static_cast<int>(keyframes.size())){
        qDebug() << "Index out of bounds";
    };

    Eigen::Affine3f tf_pos = poseToTransform(keyframes[index].pos);
    pcl::transformPointCloud(*keyframes[index].originalCloud, *keyframes[index].cloud, tf_pos);

    // emit PointCloudHandler::notifyPosUpdate(index);
}

void PointCloudHandler::setPosData(const std::array<double, 6>& arr, int index){
    if (index < 0 || index >= static_cast<int>(keyframes.size())){
        qDebug() << "Index out of bounds";
    };

    Position* p = &keyframes[index].pos;
    p->x = arr[0];
    p->y = arr[1];
    p->z = arr[2];
    p->roll = arr[3];
    p->pitch = arr[4];
    p->yaw = arr[5];

    Eigen::Affine3f tf_pos = poseToTransform(keyframes[index].pos);
    pcl::transformPointCloud(*keyframes[index].originalCloud, *keyframes[index].cloud, tf_pos);

    // std::cout << "Transform matrix:\n" << tf_pose.matrix() << std::endl;

    emit PointCloudHandler::notifyPosUpdate(index);
}

void PointCloudHandler::setPosDataFromRegistration(const std::array<double, 6>& arr, int index){
    if (index < 0 || index >= static_cast<int>(keyframes.size())){
        qDebug() << "Index out of bounds";
    };

    Position correction;
    correction.x = arr[0];
    correction.y = arr[1];
    correction.z = arr[2];
    correction.roll = arr[3];
    correction.pitch = arr[4];
    correction.yaw = arr[5];

    Eigen::Affine3f tf_icp = poseToTransform(correction);
    Eigen::Affine3f tf_pos = poseToTransform(keyframes[index].pos);
    Eigen::Affine3f tf_combined = tf_icp*tf_pos;

    Position newP = transformToPose(tf_combined);
    keyframes[index].pos = newP;

    pcl::transformPointCloud(*keyframes[index].originalCloud, *keyframes[index].cloud, tf_combined);

    emit PointCloudHandler::notifyPosUpdate(index);
}

void PointCloudHandler::startNewKeyframe(int index) {

    if(index >= keyframes.size()){
        qDebug() << "Generating " + QString::number(index);
        for(int i=0; i < index - keyframes.size() + 1; i++){
            qDebug() << "Generated [" <<i<< "]";
            PointCloudPtr newCloud = std::make_shared<pcl::PointCloud<PointT>>();
            PointCloudPtr origCloud = std::make_shared<pcl::PointCloud<PointT>>();
            Position p;
            Pose pose;
            Node node;
            node.pose = pose;
            node.id = index;
            if(index == 0) node.fixed=true;

            Keyframe newKf;
            newKf.cloud = newCloud;
            newKf.originalCloud = origCloud;
            newKf.pos = p;
            newKf.nodeId = index;
            newKf.visible = true;
            keyframes.push_back(newKf);
            poseGraph.nodes.push_back(node);
        }
        currentKeyframeIndex = index;
        emit newKeyframe(index);
    }
    // currentKeyframeIndex = static_cast<int>(keyframes.size()) - 1;
}

bool PointCloudHandler::isKeyframeVisible(int index) const{
    if (index >= 0 && index < static_cast<int>(keyframes.size()))
        return keyframes[index].visible;
    return false;
}

void PointCloudHandler::setKeyframeVisible(int index, bool visible) {
    if (index >= 0 && index < static_cast<int>(keyframes.size()))
        keyframes[index].visible = visible;
}

void PointCloudHandler::setActiveKeyframe(int index){
    qDebug() << "Activer Keyframe " + QString::number(index);
    currentKeyframeIndex = index;
}

PointCloudHandler::PointCloudPtr PointCloudHandler::getKeyframe(int index) const {
    if (index >= 0 && index < keyframes.size()) {
        return keyframes[index].cloud;
    }
    return nullptr;
}
PointCloudHandler::PointCloudPtr PointCloudHandler::getCurrentKeyframe() const {
    return getKeyframe(currentKeyframeIndex);
}

int PointCloudHandler::getCurrentKeyframeIndex(){
    return currentKeyframeIndex;
}

void PointCloudHandler::clearAllKeyframes(){
    for(int index = 0; index < keyframes.size(); index++){
        keyframes[index].cloud->clear();
        keyframes[index].cloud->width = 0;
        keyframes[index].cloud->height = 1;
        keyframes[index].cloud->is_dense = false;
    }
}

bool PointCloudHandler::clearKeyframe(int index){
    if (index >= 0 && index < static_cast<int>(keyframes.size())) {
        keyframes[index].cloud->clear();
        keyframes[index].cloud->width = 0;
        keyframes[index].cloud->height = 1;
        keyframes[index].cloud->is_dense = false;

        return true;
    }else{
        qDebug() << "False";
        return false;
    }
}

const GLfloat* PointCloudHandler::getVertices() const {
    vertexBuffer_.clear();

    if (currentKeyframeIndex >= 0 && currentKeyframeIndex < static_cast<int>(keyframes.size())) {
        const auto& cloud = keyframes[currentKeyframeIndex].cloud;
        vertexBuffer_.reserve(cloud->size() * 3);
        for (const auto& pt : cloud->points) {
            vertexBuffer_ << pt.x << pt.y << pt.z;
        }
    }

    return vertexBuffer_.constData();
}

const GLfloat* PointCloudHandler::getNodeVertices(int index) const {
    vertexBuffer_.clear();

    if(index >= 0 && index < static_cast<int>(keyframes.size())){
        const auto& nodePose = poseGraph.nodes[index].pose;
        vertexBuffer_.reserve(3);
        vertexBuffer_ << nodePose.x << nodePose.y << nodePose.z;

        qDebug() << "From Get NodeVert:" << nodePose.y;
    }

    return vertexBuffer_.constData();
}

const GLfloat* PointCloudHandler::getVertices(int index) const {
    vertexBuffer_.clear();

    if (index >= 0 && index < static_cast<int>(keyframes.size())) {
        const auto& cloud = keyframes[index].cloud;
        vertexBuffer_.reserve(cloud->size() * 3);
        for (const auto& pt : cloud->points) {
            vertexBuffer_ << pt.x << pt.y << pt.z;
        }
    }

    return vertexBuffer_.constData();
}

const GLubyte* PointCloudHandler::getColors() const {
    colorBuffer_.clear();

    if (currentKeyframeIndex >= 0 && currentKeyframeIndex < static_cast<int>(keyframes.size())) {
        const auto& cloud = keyframes[currentKeyframeIndex].cloud;
        colorBuffer_.reserve(cloud->size() * 3);

        if (hasColor) {
            for (const auto& pt : cloud->points) {
                colorBuffer_ << pt.r << pt.g << pt.b;
            }
        } else {
            for (size_t i = 0; i < cloud->size(); ++i) {
                colorBuffer_ << 200 << 200 << 200; // Default gray
            }
        }
    }

    return colorBuffer_.constData();
}

const GLubyte* PointCloudHandler::getColors(int index) const {
    colorBuffer_.clear();

    if (index >= 0 && index < static_cast<int>(keyframes.size())) {
        const auto& cloud = keyframes[index].cloud;
        colorBuffer_.reserve(cloud->size() * 3);

        if (hasColor) {
            for (const auto& pt : cloud->points) {
                colorBuffer_ << pt.r << pt.g << pt.b;
            }
        } else {
            uint8_t r, g, b;
            std::tie(r, g, b) = getColorFromIndex(index);

            for (size_t i = 0; i < cloud->size(); ++i) {
                colorBuffer_ << r << g << b; // Default gray
            }
        }
    }

    return colorBuffer_.constData();
}

const GLubyte* PointCloudHandler::getNodeColor(int index) const {
    colorBuffer_.clear();

    if (index >= 0 && index < static_cast<int>(keyframes.size())) {
        uint8_t r, g, b;
        std::tie(r, g, b) = getColorFromIndex(index);

        // Push back a single RGB triple
        colorBuffer_ << r << g << b;
    } else {
        // Fallback default (gray)
        colorBuffer_ << 200 << 200 << 200;
    }

    return colorBuffer_.constData();
}


int PointCloudHandler::getVertexCount() const {
    if (currentKeyframeIndex >= 0 && currentKeyframeIndex < static_cast<int>(keyframes.size())) {
        return static_cast<int>(keyframes[currentKeyframeIndex].cloud->points.size());
    }
    return 0;
}

int PointCloudHandler::getVertexCount(int index) const {
    if (index >= 0 && index < static_cast<int>(keyframes.size())) {
        return static_cast<int>(keyframes[index].cloud->points.size());
    }
    return 0;
}

int PointCloudHandler::getKeyframeCount() const {
    return keyframes.size();
}

void PointCloudHandler::rotateKeyframe(int index, float angleDegrees) {
    if (index < 0 || index >= keyframes.size()) return;

    float angleRadians = angleDegrees * M_PI / 180.0f;

    Eigen::Affine3f transform = Eigen::Affine3f::Identity();
    transform.rotate(Eigen::AngleAxisf(angleRadians, Eigen::Vector3f::UnitY()));

    pcl::transformPointCloud(*keyframes[index].cloud, *keyframes[index].cloud, transform);
}

void PointCloudHandler::setReference(int index){
    referenceFrameIndex = index;
}

void PointCloudHandler::combineKeyframes() {
    combinedCloud_original.reset(new pcl::PointCloud<PointT>());

    for (const auto& kf : keyframes) {
        if (kf.cloud && !kf.cloud->empty()) {
            *combinedCloud_original += *kf.cloud;
        }
    }

    combinedCloud_processed = std::make_shared<CloudT>(*combinedCloud_original);

    qDebug() << "Combined cloud has" << combinedCloud_original->size() << "points from" << keyframes.size() << "keyframes.";
}

pcl::PointCloud<pcl::PointXYZRGB>::Ptr PointCloudHandler::getCombinedKeyframe() const {
    return combinedCloud_processed;  // assuming this is where combineKeyframes() stores the result
}

void PointCloudHandler::cleanKeyframe(){
    int index = currentKeyframeIndex;

    // 1) Clean per keyframe
    pcl::PointCloud<PointT>::Ptr clean(new pcl::PointCloud<PointT>);
    std::vector<int> idx;
    pcl::removeNaNFromPointCloud(*keyframes[index].cloud, *clean, idx);

    // PassThrough (example on Z)
    pcl::PassThrough<PointT> pass;
    pass.setInputCloud(clean);
    pass.setFilterFieldName("y");
    pass.setFilterLimits(-0.2f, Y_OFFSET/50);
    pass.filter(*clean);

    // VoxelGrid
    pcl::VoxelGrid<PointT> vox;
    vox.setInputCloud(clean);
    vox.setLeafSize(0.1f, 0.1f, 0.1f); // 1 cm spacing → tune this
    vox.filter(*clean);

    // StatisticalOutlierRemoval
    pcl::StatisticalOutlierRemoval<PointT> sor;
    sor.setInputCloud(clean);
    sor.setMeanK(20);             // 15–50 typical
    sor.setStddevMulThresh(1.0);  // 0.8–1.5 typical
    sor.filter(*clean);

    keyframes[index].cloud = clean;
}

void PointCloudHandler::revertToPreClean(){
    int index = currentKeyframeIndex;
    if (history.size() > 1) {
        keyframes[index].cloud = history.front();
        history.resize(1);
    }
}

void PointCloudHandler::undoLatestClean(){
    int index = currentKeyframeIndex;
    if (history.size() > 1) {
        redoStack.push_back(keyframes[index].cloud);
        keyframes[index].cloud = history.back();
        history.pop_back();
    }
}

void PointCloudHandler::redoLatestClean(){
    int index = currentKeyframeIndex;
    if (!redoStack.empty()) {
        history.push_back(keyframes[index].cloud);
        keyframes[index].cloud = history.back();
        redoStack.pop_back();
    }
}

void PointCloudHandler::tryRegister(int sourceIndex, int targetIndex, double maxCorrDist, int maxIter, double fitThresh){

    RegistrationResult result;
    result.success = false;
    result.transformation = Eigen::Matrix4f::Identity();
    result.fitness_score = 1e9;

    PointCloudPtr source = keyframes[sourceIndex].cloud;
    PointCloudPtr target = keyframes[targetIndex].cloud;

    pcl::PointCloud<pcl::PointXYZ>::Ptr source_xyz(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::copyPointCloud(*source, *source_xyz);
    pcl::PointCloud<pcl::PointXYZ>::Ptr target_xyz(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::copyPointCloud(*target, *target_xyz);

    pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
    icp.setInputSource(source_xyz);
    icp.setInputTarget(target_xyz);
    icp.setMaxCorrespondenceDistance(maxCorrDist);
    icp.setMaximumIterations(maxIter);
    icp.setTransformationEpsilon(1e-8);
    icp.setEuclideanFitnessEpsilon(1e-6);

    pcl::PointCloud<pcl::PointXYZ> aligned;
    icp.align(aligned);

    if (icp.hasConverged()) {
        double score = icp.getFitnessScore();
        if (score < fitThresh) {
            result.success = true;
            result.transformation = icp.getFinalTransformation();
            result.fitness_score = score;

            Eigen::Vector3f translation = result.transformation.block<3,1>(0,3);
            Eigen::Matrix3f rotation = result.transformation.block<3,3>(0,0);
            Eigen::Vector3f euler = rotation.eulerAngles(0, 1, 2);

            std::array<double, 6> pose = {
                static_cast<double>(translation.x()),
                static_cast<double>(translation.y()),
                static_cast<double>(translation.z()),
                static_cast<double>(euler[0]),
                static_cast<double>(euler[1]),
                static_cast<double>(euler[2])
            };

            setPosDataFromRegistration(pose, sourceIndex);
        }
    }

    if(result.success){
        emit PointCloudHandler::visRegisterKeyframe(sourceIndex, targetIndex, result);
    }else{
        qDebug() << "Failed to Register with score: " << result.fitness_score;
    }
}

void PointCloudHandler::applyPassThrough(std::string axis, int min, int max){
    int index = currentKeyframeIndex;

    pcl::PointCloud<PointT>::Ptr clean(new pcl::PointCloud<PointT>);
    std::vector<int> idx;
    pcl::removeNaNFromPointCloud(*keyframes[index].cloud, *clean, idx);

    pcl::PassThrough<PointT> pass;
    pass.setInputCloud(clean);
    pass.setFilterFieldName("y");
    pass.setFilterLimits(-0.2f, Y_OFFSET/50);
    pass.filter(*clean);

    if(history.empty()){
        pcl::PointCloud<PointT>::Ptr preCleanCloud(new pcl::PointCloud<PointT>(*keyframes[index].cloud));
        history.push_back(preCleanCloud);
    }
    history.push_back(clean);
    keyframes[index].cloud = clean;
}

void PointCloudHandler::applyVoxelGrid(double leafSize){
    int index = currentKeyframeIndex;

    pcl::PointCloud<PointT>::Ptr clean(new pcl::PointCloud<PointT>);
    std::vector<int> idx;
    pcl::removeNaNFromPointCloud(*keyframes[index].cloud, *clean, idx);

    // VoxelGrid
    pcl::VoxelGrid<PointT> vox;
    vox.setInputCloud(clean);
    vox.setLeafSize(leafSize, leafSize, leafSize); // 1 cm spacing → tune this
    vox.filter(*clean);

    if(history.empty()){
        pcl::PointCloud<PointT>::Ptr preCleanCloud(new pcl::PointCloud<PointT>(*keyframes[index].cloud));
        history.push_back(preCleanCloud);
    }
    history.push_back(clean);
    keyframes[index].cloud = clean;
}

void PointCloudHandler::applyVoxedToCombined(double leafSize){

    for (const auto& kf : keyframes) {
        if (kf.cloud && !kf.cloud->empty()) {
            *combinedCloud_original += *kf.cloud;
        }
    }

    pcl::PointCloud<PointT>::Ptr clean(new pcl::PointCloud<PointT>);
    std::vector<int> idx;
    pcl::removeNaNFromPointCloud(*combinedCloud_original, *clean, idx);

    // VoxelGrid
    pcl::VoxelGrid<PointT> vox;
    vox.setInputCloud(clean);
    vox.setLeafSize(leafSize, leafSize, leafSize); // 1 cm spacing → tune this
    vox.filter(*clean);

    combinedCloud_processed = clean;
}

void PointCloudHandler::applySOR(int meanK, double stddev){
    int index = currentKeyframeIndex;

    pcl::PointCloud<PointT>::Ptr clean(new pcl::PointCloud<PointT>);
    std::vector<int> idx;
    pcl::removeNaNFromPointCloud(*keyframes[index].cloud, *clean, idx);

    // StatisticalOutlierRemoval
    pcl::StatisticalOutlierRemoval<PointT> sor;
    sor.setInputCloud(clean);
    sor.setMeanK(meanK);             // 15–50 typical
    sor.setStddevMulThresh(stddev);  // 0.8–1.5 typical
    sor.filter(*clean);

    if(history.empty()){
        pcl::PointCloud<PointT>::Ptr preCleanCloud(new pcl::PointCloud<PointT>(*keyframes[index].cloud));
        history.push_back(preCleanCloud);
    }
    history.push_back(clean);
    keyframes[index].cloud = clean;
}

void PointCloudHandler::applyMirrorCorrect(double maxY){
    int index = currentKeyframeIndex;

    pcl::PointCloud<PointT>::Ptr clean(new pcl::PointCloud<PointT>);
    std::vector<int> idx;
    pcl::removeNaNFromPointCloud(*keyframes[index].cloud, *clean, idx);


    pcl::PointCloud<PointT>::Ptr corrected(new pcl::PointCloud<PointT>);
    corrected->reserve(clean->size());

    float pitch = keyframes[index].pos.pitch;
    maxY = maxY*cos(pitch*(M_PI/180.0f))/50;

    for (const auto& pt : clean->points) {
        PointT newPt = pt;
        if (pt.y < -0.5) {
            double shiftedY = pt.y + maxY;
            newPt.y = -shiftedY;

            qDebug() << newPt.y;
        }
        corrected->push_back(newPt);
    }

    corrected->width  = corrected->size();
    corrected->height = 1;
    corrected->is_dense = false;

    keyframes[index].cloud = corrected;
}

void PointCloudHandler::filterKeyframe(float radius, float upsampleRadius, float upsampleStep, int order){


    // qDebug() << "Smoothing all keyframes with" << combinedCloud->size() << "total points.";

    // Optional: Backup the combined original point cloud
    combinedCloud_original = PointCloudPtr(new pcl::PointCloud<pcl::PointXYZRGB>(*combinedCloud_processed));
    qDebug() << "Original combined point cloud backed up.";

    // Step 2: Set up MLS smoothing
    pcl::MovingLeastSquares<pcl::PointXYZRGB, pcl::PointXYZRGB> mls;
    mls.setInputCloud(combinedCloud_processed);

    // Use a KD-tree for neighborhood search
    pcl::search::KdTree<pcl::PointXYZRGB>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZRGB>);
    mls.setSearchMethod(tree);
    mls.setSearchRadius(radius);  // e.g. 0.01 (meters)

    // Optional settings
    mls.setUpsamplingMethod(pcl::MovingLeastSquares<pcl::PointXYZRGB, pcl::PointXYZRGB>::SAMPLE_LOCAL_PLANE);
    mls.setUpsamplingRadius(upsampleRadius);    // Area around each point to sample
    mls.setUpsamplingStepSize(upsampleStep);// larger if step size is coarse
    mls.setSqrGaussParam(radius * radius);
    mls.setComputeNormals(true);
    mls.setPolynomialOrder(order);  // 2nd-order polynomial

    // Output smoothed cloud
    PointCloudPtr smoothed(new pcl::PointCloud<pcl::PointXYZRGB>);
    mls.process(*smoothed);

    if (!smoothed->empty()) {
        *combinedCloud_processed = *smoothed;
        qDebug() << "Smoothed: " << smoothed->size() << " points";
    } else {
        qDebug() << "MLS produced an empty cloud; keeping original.";
    }
}

void PointCloudHandler::revertKeyframe() {
    if (combinedCloud_original && !combinedCloud_original->empty()) {
        combinedCloud_processed = std::make_shared<CloudT>(*combinedCloud_original);
        qDebug() << "Reverted combined cloud to original.";
    } else {
        qDebug() << "No backup exists for combined cloud.";
    }
}

void PointCloudHandler::registerKeyframe(int referenceIndex, int currentIndex) {
    if(currentIndex == 0 || currentIndex == referenceIndex) return;

    currentIndex = currentKeyframeIndex;
    referenceIndex = currentKeyframeIndex-1;

    if (referenceIndex < 0 || currentIndex < 0 ||
        referenceIndex >= keyframes.size() || currentIndex >= keyframes.size()) {
        qWarning() << "Invalid keyframe indices";
        return;
    }

    using NormalT = pcl::Normal;
    using FeatureT = pcl::FPFHSignature33;
    using NormalCloudT = pcl::PointCloud<NormalT>;
    using FeatureCloudT = pcl::PointCloud<FeatureT>;

    auto source = keyframes[currentIndex].cloud;
    auto target = keyframes[referenceIndex].cloud;

    // 1. Downsample both clouds
    pcl::VoxelGrid<PointT> voxelGrid;
    voxelGrid.setLeafSize(leafx, leafy, leafz);

    PointCloudPtr sourceFiltered(new pcl::PointCloud<PointT>);
    voxelGrid.setInputCloud(source);
    voxelGrid.filter(*sourceFiltered);

    PointCloudPtr targetFiltered(new pcl::PointCloud<PointT>);
    voxelGrid.setInputCloud(target);
    voxelGrid.filter(*targetFiltered);

    // 2. Estimate normals
    pcl::NormalEstimation<PointT, NormalT> ne;
    pcl::search::KdTree<PointT>::Ptr tree(new pcl::search::KdTree<PointT>);
    ne.setSearchMethod(tree);
    ne.setKSearch(kNeighbors);

    NormalCloudT::Ptr sourceNormals(new NormalCloudT);
    ne.setInputCloud(sourceFiltered);
    ne.compute(*sourceNormals);

    NormalCloudT::Ptr targetNormals(new NormalCloudT);
    ne.setInputCloud(targetFiltered);
    ne.compute(*targetNormals);

    // 3. Compute FPFH features
    pcl::FPFHEstimation<PointT, NormalT, FeatureT> fpfh;
    fpfh.setSearchMethod(tree);
    fpfh.setRadiusSearch(searchRadius);

    FeatureCloudT::Ptr sourceFeatures(new FeatureCloudT);
    fpfh.setInputCloud(sourceFiltered);
    fpfh.setInputNormals(sourceNormals);
    fpfh.compute(*sourceFeatures);

    FeatureCloudT::Ptr targetFeatures(new FeatureCloudT);
    fpfh.setInputCloud(targetFiltered);
    fpfh.setInputNormals(targetNormals);
    fpfh.compute(*targetFeatures);

    // 4. SAC-IA initial alignment
    pcl::SampleConsensusPrerejective<PointT, PointT, FeatureT> sac_ia;
    sac_ia.setInputSource(sourceFiltered);
    sac_ia.setSourceFeatures(sourceFeatures);
    sac_ia.setInputTarget(targetFiltered);
    sac_ia.setTargetFeatures(targetFeatures);
    sac_ia.setMaximumIterations(maxIterations);
    sac_ia.setNumberOfSamples(sampleSize);
    sac_ia.setCorrespondenceRandomness(correspondenceRandomness);
    sac_ia.setSimilarityThreshold(similarityThresh);
    sac_ia.setMaxCorrespondenceDistance(maxCorrespondenceDistance);
    sac_ia.setInlierFraction(inlierFraction);

    PointCloudPtr aligned(new pcl::PointCloud<PointT>);
    sac_ia.align(*aligned);

    if (!sac_ia.hasConverged()) {
        qWarning() << "[SAC-IA] Alignment failed.";
        return;
    }

    // 5. ICP refinement
    pcl::IterativeClosestPoint<PointT, PointT> icp;
    icp.setInputSource(aligned);
    icp.setInputTarget(targetFiltered);
    icp.setMaximumIterations(icpMaxIterations);

    PointCloudPtr finalAligned(new pcl::PointCloud<PointT>);
    icp.align(*finalAligned);

    if (icp.hasConverged()) {
        qDebug() << "[ICP] Fitness score:" << icp.getFitnessScore();
        *keyframes[currentIndex].cloud = *finalAligned;  // Overwrite original with aligned
    } else {
        qWarning() << "[ICP] Refinement failed.";
    }
}

inline Eigen::Matrix4f positionToMatrix(const Position& pos) {
    using namespace Eigen;

    AngleAxisf rollAngle (static_cast<float>(pos.roll),  Vector3f::UnitX());
    AngleAxisf pitchAngle(static_cast<float>(pos.pitch), Vector3f::UnitZ());
    AngleAxisf yawAngle  (static_cast<float>(pos.yaw),   Vector3f::UnitY());

    Matrix3f R = (yawAngle * pitchAngle * rollAngle).toRotationMatrix();

    Matrix4f T = Matrix4f::Identity();
    T.block<3,3>(0,0) = R;
    T(0,3) = static_cast<float>(pos.x);
    T(1,3) = static_cast<float>(pos.y);
    T(2,3) = static_cast<float>(pos.z);

    return T;
}

// Update Position from transform matrix
inline void matrixToPosition(const Eigen::Matrix4f& T, Position& pos) {
    Eigen::Vector3f t = T.block<3,1>(0,3);
    pos.x = t.x(); pos.y = t.y(); pos.z = t.z();

    Eigen::Matrix3f R = T.block<3,3>(0,0);
    Eigen::Vector3f euler = R.eulerAngles(0,1,2); // roll, pitch, yaw
    pos.roll = euler[0];
    pos.pitch = euler[1];
    pos.yaw = euler[2];
}

void PointCloudHandler::registerPairwise(double maxCorrDist,
                                         int maxIter,
                                         double fitThresh)
{
    if (keyframes.size() < 2) return;

    // Always start fresh combined cloud
    combinedCloud_original.reset(new pcl::PointCloud<Keyframe::PointT>());

    for (size_t i = 0; i < keyframes.size(); ++i) {
        if (!keyframes[i].originalCloud || keyframes[i].originalCloud->empty()) {
            std::cerr << "[ICP] Empty/null originalCloud at frame " << i << std::endl;
            continue;
        }

        Eigen::Matrix4f Ti = positionToMatrix(keyframes[i].pos);

        if (i > 0) {
            if (!keyframes[i-1].cloud || keyframes[i-1].cloud->empty()) {
                std::cerr << "[ICP] No valid previous cloud for frame " << i << std::endl;
            } else {
                pcl::IterativeClosestPoint<Keyframe::PointT, Keyframe::PointT> icp;
                icp.setMaximumIterations(maxIter);
                icp.setMaxCorrespondenceDistance(maxCorrDist);
                icp.setTransformationEpsilon(1e-6);
                icp.setEuclideanFitnessEpsilon(1e-6);

                icp.setInputSource(keyframes[i].cloud); // always raw
                icp.setInputTarget(keyframes[i-1].cloud);       // previous posed

                pcl::PointCloud<Keyframe::PointT> aligned;
                try {
                    icp.align(aligned, Ti);
                } catch (const std::exception& e) {
                    std::cerr << "[ICP] Exception at frame " << i << ": " << e.what() << std::endl;
                    continue;
                }

                if (icp.hasConverged() && icp.getFitnessScore() < fitThresh) {
                    Eigen::Matrix4f refined = icp.getFinalTransformation();
                    matrixToPosition(refined, keyframes[i].pos);
                    Ti = refined;
                }

                std::cout << "[ICP] frame " << i
                          << " fitness=" << icp.getFitnessScore()
                          << " converged=" << icp.hasConverged()
                          << std::endl;
            }
        }

        // Always rebuild posed cloud fresh from original
        keyframes[i].cloud.reset(new pcl::PointCloud<Keyframe::PointT>());
        pcl::transformPointCloud(*keyframes[i].originalCloud,
                                 *keyframes[i].cloud,
                                 Ti);

        // Add to combined map
        *combinedCloud_original += *keyframes[i].cloud;
    }
}


void PointCloudHandler::reconstructSurface() {
    if (keyframes.empty()) {
        qWarning() << "[PointCloudHandler] No keyframes to combine.";
        return;
    }


    // if (combinedCloud->empty()) {
    //     qWarning() << "[PointCloudHandler] Combined point cloud is empty.";
    //     return;
    // }

    // Run Marching Cubes

    pcl::NormalEstimation<PointT, pcl::Normal> ne;
    // ne.setInputCloud(combinedCloud);
    pcl::search::KdTree<PointT>::Ptr tree(new pcl::search::KdTree<PointT>());
    ne.setSearchMethod(tree);
    ne.setKSearch(20);

    pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>);
    ne.compute(*normals);

    pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloudWithNormals(new pcl::PointCloud<pcl::PointXYZRGBNormal>);
    // pcl::concatenateFields(*combinedCloud, *normals, *cloudWithNormals);

    pcl::MarchingCubesRBF<pcl::PointXYZRGBNormal> mc;
    mc.setInputCloud(cloudWithNormals);
    mc.setGridResolution(70, 70, 70);

    pcl::PolygonMesh::Ptr mesh(new pcl::PolygonMesh);
    mc.reconstruct(*mesh);

    if (mesh->polygons.empty()) {
        qWarning() << "[PointCloudHandler] Marching Cubes returned empty mesh.";
        return;
    }

    // Convert to vertex data
    pcl::PointCloud<PointT> meshPoints;
    pcl::fromPCLPointCloud2(mesh->cloud, meshPoints);

    meshVertices.clear();
    meshIndices.clear();

    for (const auto& pt : meshPoints) {
        meshVertices.push_back(pt.x);
        meshVertices.push_back(pt.y);
        meshVertices.push_back(pt.z);
        meshVertices.push_back(pt.r / 255.0f);
        meshVertices.push_back(pt.g / 255.0f);
        meshVertices.push_back(pt.b / 255.0f);
    }

    for (const auto& poly : mesh->polygons) {
        for (auto index : poly.vertices) {
            meshIndices.push_back(index);
        }
    }

    qDebug() << "[PointCloudHandler] Mesh generated with"
             << meshVertices.size() / 6 << "vertices and"
             << meshIndices.size() / 3 << "triangles.";
}

const std::vector<float>& PointCloudHandler::getMeshVertices() const {
    return meshVertices;
}

const std::vector<unsigned int>& PointCloudHandler::getMeshIndices() const {
    return meshIndices;
}

void PointCloudHandler::changeFloatParam(QString param, float val){
    qDebug() << param + ": " + QString::number(val);

    if(param == "voxSizeX") leafx = val;
    else if(param == "voxSizeY") leafy = val;
    else if(param == "voxSizeZ") leafz = val;
    else if(param == "fSearchR") searchRadius = val;
    else if(param == "simThresh") similarityThresh = val;
    else if(param == "maxCorrDist") maxCorrespondenceDistance = val;
    else if(param == "inFrac") inlierFraction = val;
}

void PointCloudHandler::changeIntParam(QString param, int val){
    qDebug() << param + ": " + QString::number(val);

    if(param == "kNeigh") kNeighbors = val;
    else if(param == "maxIter") maxIterations = val;
    else if(param == "corrRand") correspondenceRandomness = val;
    else if(param == "sampSize") sampleSize = val;
    else if(param == "icpMaxIter") icpMaxIterations = val;
}

void PointCloudHandler::saveKeyframe(const QString& filename, const QString& directoryPath, int mode){
    int i = currentKeyframeIndex;

    //Mode 0: Save Keyframe
    //Mode 1: Save Keyframes as One
    //Mode 2: Save All Keyframes Separately

    if(mode == 0){
        PointCloudIO::saveKeyframe(*this, filename, i);
    }else if (mode == 1){
        PointCloudIO::saveAsOnePCD(*this, filename);
    }else if (mode == 2){
        PointCloudIO::saveAllKeyframes(*this, filename, directoryPath);
    }else if (mode == 3){
        PointCloudIO::saveSessionData(*this, filename, directoryPath);
    }
}

void PointCloudHandler::loadSession(const QString& sessionFile, const QString& dir){
    PointCloudIO::loadSessionData(*this, sessionFile, dir);
}
