#pragma once
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <memory>

using PointT = pcl::PointXYZRGB;
using CloudT = pcl::PointCloud<PointT>;
using PointCloudPtr = std::shared_ptr<CloudT>;
