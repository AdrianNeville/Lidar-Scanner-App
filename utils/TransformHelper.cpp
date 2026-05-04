#include "helpers/TransformHelper.h"

Eigen::Matrix4d TransformHelper::computeRelativeFromEncoders(const Pose& prev, const Pose& next, double radius) {
    // Δ angles
    double dYaw   = next.yaw   - prev.yaw;   // azimuth difference
    double dPitch = next.pitch - prev.pitch; // elevation difference

    // Build relative rotation (order: yaw → pitch)
    Eigen::Isometry3d T = Eigen::Isometry3d::Identity();
    T.linear() = (Eigen::AngleAxisd(dYaw   * M_PI / 180.0, Eigen::Vector3d::UnitY()) *   // yaw around Y
                  Eigen::AngleAxisd(dPitch * M_PI / 180.0, Eigen::Vector3d::UnitX())     // pitch around X
                  ).toRotationMatrix();

    // Debug printouts
    qDebug() << "==== computeRelativeFromEncoders ====";
    qDebug() << "Prev Pose: yaw=" << prev.yaw << " pitch=" << prev.pitch;
    qDebug() << "Next Pose: yaw=" << next.yaw << " pitch=" << next.pitch;
    qDebug() << "ΔYaw =" << dYaw << "ΔPitch =" << dPitch;

    // Rotation matrix
    Eigen::Matrix3d R = T.linear();
    qDebug() << "Rotation matrix:";
    for (int i = 0; i < 3; ++i) {
        qDebug() << R(i,0) << R(i,1) << R(i,2);
    }

    // Orthogonality check
    Eigen::Matrix3d shouldBeI = R * R.transpose();
    qDebug() << "R * R^T (should be Identity):";
    for (int i = 0; i < 3; ++i) {
        qDebug() << shouldBeI(i,0) << shouldBeI(i,1) << shouldBeI(i,2);
    }

    // Determinant check
    double det = R.determinant();
    qDebug() << "det(R) =" << det;

    return T.matrix();
}
