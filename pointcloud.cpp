#include "pointcloud.h"

PointCloud::PointCloud() {}

void PointCloud::addPoint(GLfloat d, GLfloat r, GLfloat s){
    QMutexLocker locker(&mutex);
    points.push_back(d);
    points.push_back(r);
    points.push_back(s);
}

std::vector<GLfloat> PointCloud::getPoints() const{
    QMutexLocker locker(&mutex);
    return points;
}
