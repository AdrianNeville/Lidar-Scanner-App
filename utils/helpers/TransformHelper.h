#pragma once
#include <Eigen/Dense>
#include "types/pose.h"

class TransformHelper {
public:
    // Compute relative transform between two poses based on encoder values
    static Eigen::Matrix4d computeRelativeFromEncoders(const Pose& prev, const Pose& next, double radius = 0.0);
};
