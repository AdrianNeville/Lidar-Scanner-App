#ifndef PCDDATA_H
#define PCDDATA_H

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <QString>


class PCDData
{
public:
    PCDData();

    void loadFromFile(const QString& path);

private:
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
};

#endif // PCDDATA_H
