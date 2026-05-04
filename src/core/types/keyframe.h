#pragma once
#include <memory>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include "position.h"
#include "node.h"


struct Keyframe {
    using PointT = pcl::PointXYZRGB;
    using PointCloudPtr = std::shared_ptr<pcl::PointCloud<PointT>>;

    PointCloudPtr cloud;
    PointCloudPtr originalCloud;
    Position pos;
    int nodeId;
    bool visible = true;
};
