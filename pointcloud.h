#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include <vector>
#include <QMutex>
#include <QtOpenGL>
#include <QtOpenGL>

class PointCloud
{

private:
    mutable QMutex mutex;
    std::vector<GLfloat> points;

public:
    PointCloud();
    void addPoint(GLfloat d, GLfloat r, GLfloat s);
    std::vector<GLfloat> getPoints() const;
    // void clear();
};

#endif // POINTCLOUD_H
