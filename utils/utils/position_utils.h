// pose_utils.h
#pragma once
#include "types/position.h"         // where Pose is defined
#include <Eigen/Geometry>
#include <pcl/pcl_macros.h>

inline Eigen::Affine3f poseToTransform(const Position& p) {
    Eigen::Affine3f t = Eigen::Affine3f::Identity();
    t.translation() << p.x, p.y, p.z;
    t.rotate(Eigen::AngleAxisf(p.roll * M_PI/180.0f, Eigen::Vector3f::UnitZ()));
    t.rotate(Eigen::AngleAxisf(p.yaw * M_PI/180.0f, Eigen::Vector3f::UnitY()));
    t.rotate(Eigen::AngleAxisf(p.pitch * M_PI/180.0f, Eigen::Vector3f::UnitX()));

    return t;
}

// New function: transformToPose
inline Position transformToPose(const Eigen::Affine3f& t) {
    Position p;
    Eigen::Vector3f translation = t.translation();
    p.x = translation.x();
    p.y = translation.y();
    p.z = translation.z();

    // Extract rotation angles (Z-Y-X order, matching poseToTransform)
    Eigen::Vector3f euler = t.rotation().eulerAngles(2, 1, 0); // Z, Y, X

    p.roll  = euler[0] * 180.0f / M_PI; // around Z
    p.yaw   = euler[1] * 180.0f / M_PI; // around Y
    p.pitch = euler[2] * 180.0f / M_PI; // around X

    return p;
}
