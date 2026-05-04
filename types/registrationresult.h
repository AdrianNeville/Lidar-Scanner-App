#pragma once
#include <Eigen/Dense>

struct RegistrationResult {
    bool success;
    Eigen::Matrix4f transformation;
    double fitness_score;
};
