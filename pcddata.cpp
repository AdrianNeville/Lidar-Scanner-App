#include "pcddata.h"

PCDData::PCDData()
{
    cloud = new cloud(pcl::PointCloud<pcl::PointXYZ>;
}

PCDData::loadFromFile(const QString& path){
    if (pcl::io::loadPCDFile<pcl::PointXYZ> (path, *cloud) == -1) //* load the file
    {
        PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
        return (-1);
    }
}
