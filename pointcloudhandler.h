#pragma once

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <boost/make_shared.hpp>
#include <QOpenGLFunctions>
#include <QString>
#include <QVector>
#include <QObject>
#include <pcl/io/pcd_io.h>
#include <QDir>
#include <unordered_map>
#include "types/keyframe.h"
#include "posegraph.h"
#include "types/registrationresult.h"

class PointCloudIO;

class PointCloudHandler : public QObject{
    Q_OBJECT
public:
    using PointT = pcl::PointXYZRGB;
    using CloudT = pcl::PointCloud<PointT>;
    using PointCloudPtr = std::shared_ptr<pcl::PointCloud<PointT>>;

    friend class PointCloudIO;

    explicit PointCloudHandler(QObject* parent = nullptr);
    void startNewKeyframe(int index);

    //Backups
    std::unordered_map<int, PointCloudPtr> originalKeyframes;

    // Loaders
    bool loadFromFile(const QString& path, int index);
    void loadSession(const QString& sessionFile, const QString& dir);
    //Saving
    void saveKeyframe(const QString& filename, const QString& directoryPath, int mode);


    //Scanning
    void addLidarPoint(float x, float y, float z, double pitch, double yaw, int keyframeIndex);
    void addNode(double elev, double azim, int index);
    void addEdge(int from, int to,
                 const Eigen::Matrix4d& rel_pose,
                 const Eigen::Matrix<double,6,6>& info);
    void setActiveKeyframe(int index);
    bool clearKeyframe(int index);
    void clearAllKeyframes();
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr getKeyframe(int index) const;
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr getCurrentKeyframe() const;
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr getCombinedKeyframe() const;
    int getCurrentKeyframeIndex();
    std::array<double, 6> getPosData(int index);
    Pose* getPoseData(int index);
    void loadPointsfromSession(int kfCount);
    void setPosData(int index);
    void setPosData(const std::array<double, 6>& arr, int index);
    void setPosDataFromRegistration(const std::array<double, 6> &arr, int index);
    void showMergedKeyframes(bool enabled);
    bool isKeyframeVisible(int index) const;
    void setKeyframeVisible(int index, bool visible);

    //Cleaning
    void cleanKeyframe();
    void revertToPreClean();
    void undoLatestClean();
    void redoLatestClean();
    void applyPassThrough(std::string axis, int min, int max);
    void applyVoxelGrid(double leafSize);
    void applySOR(int meanK, double stdev);
    void applyMirrorCorrect(double maxY);
    void applyVoxedToCombined(double leafSize);

    void tryRegister(int sourceIndex, int targetIndex, double maxCorrDist, int maxIter, double fitThresh);

    //Processing
    void setReference(int index);
    void registerKeyframe(int referenceIndex, int currentIndex);
    void changeFloatParam(QString param, float value);
    void changeIntParam(QString param, int value);
    void reconstructSurface();
    void filterKeyframe(float radius, float upsampleRadius, float upsampleStep, int order);
    void combineKeyframes();
    void revertKeyframe();


    void registerPairwise( double maxCorrDist, int maxIter, double fitThresh);

    //Debugging
    void rotateKeyframe(int index, float angleDegrees);

    //Pose Handling
    Position getPos(int index) const;
    void setPos(int index, const Position& pos);
    void calculateTransformOnPoints();


    // OpenGL data
    const GLfloat* getVertices() const;
    const GLubyte* getColors() const;
    const GLfloat* getVertices(int index) const;
    const GLubyte* getColors(int index) const;
    const GLfloat* getNodeVertices(int index) const;
    const GLubyte* getNodeColor(int index) const;
    int getVertexCount() const;
    int getVertexCount(int index) const;
    int getKeyframeCount() const;
    bool hasColor = false;

    //Mesh data
    const std::vector<float>& getMeshVertices() const;
    const std::vector<unsigned int>& getMeshIndices() const;
signals:
    void newKeyframe(int index);
    void notifyPosUpdate(int index);
    void visRegisterKeyframe(int sourceIndex, int targetIndex, RegistrationResult res);
    void updateByLoadSession(int kfCount);
    void updateComboCount(int kfCount);

private:

    //Worker Thread
        QThread* workerThread;

    bool loadFromPCD(const QString& path);
    bool loadFromPLY(const QString& path);

    CloudT::Ptr cloud_;
    mutable QVector<GLfloat> vertexBuffer_;
    mutable QVector<GLubyte> colorBuffer_;

    CloudT::Ptr combinedCloud_processed;
    PointCloudPtr combinedCloud_original;

    std::vector<Keyframe> keyframes;
    int currentKeyframeIndex = -1;
    int referenceFrameIndex = 0;

    PoseGraph poseGraph;

    //History Stacks
    std::vector<PointCloudPtr> history;
    std::vector<PointCloudPtr> redoStack;

    //Voxel Grid
    float leafx = 0.01f;
    float leafy = 0.01f;
    float leafz = 0.01f;

    //Normal Estimation
    int kNeighbors = 10;

    //FPFH
    float searchRadius = 0.05f;

    //SAC-IA
    int maxIterations = 50000;
    int sampleSize = 3;
    int correspondenceRandomness = 5;
    float similarityThresh = 0.9f;
    float maxCorrespondenceDistance = 2.5f * 0.01f;
    float inlierFraction = 0.25f;

    //ICP
    int icpMaxIterations = 50;

    //Mesh
    std::vector<float> meshVertices;       // Interleaved x y z r g b
    std::vector<unsigned int> meshIndices; // Triangle indices
};
