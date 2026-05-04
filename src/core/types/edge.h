#pragma once
#include "types/pose.h"
#include <Eigen/Dense>

struct Edge {
    int from;   // nodeId of source
    int to;     // nodeId of target

    Eigen::Matrix4d relative_pose;   // relative transform T_from_to
    Eigen::Matrix<double,6,6> information; // uncertainty (inverse of covariance)
};
