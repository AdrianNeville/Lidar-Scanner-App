#include <QCoreApplication>
#include <QDebug>
#include <sstream>              // <-- needed for ostringstream
#include "helpers/TransformHelper.h"

QString eigenToQString(const Eigen::Matrix4d& mat) {
    std::ostringstream oss;
    oss << mat.format(Eigen::IOFormat(4, 0, ", ", "\n", "[", "]"));
    return QString::fromStdString(oss.str());
}

void runTests() {
    qDebug() << "Running TransformHelper tests...";

    // --- Identity test ---
    Pose p0(0, 0);
    Pose p1(0, 0);
    auto T1 = TransformHelper::computeRelativeFromEncoders(p0, p1);
    qDebug() << "Identity test:\n" << eigenToQString(T1);

    // --- Yaw 90 test ---
    Pose yaw0(0, 0);
    Pose yaw90(0, 90);
    auto T2 = TransformHelper::computeRelativeFromEncoders(yaw0, yaw90);
    qDebug() << "Yaw 90 test:\n" << eigenToQString(T2);

    // --- Pitch 30 test ---
    Pose pitch0(0, 0);
    Pose pitch30(30, 0);
    auto T3 = TransformHelper::computeRelativeFromEncoders(pitch0, pitch30);
    qDebug() << "Pitch 30 test:\n" << eigenToQString(T3);

    // --- Combined yaw + pitch test ---
    Pose mixed0(0, 0);
    Pose mixed(30, 90);
    auto T4 = TransformHelper::computeRelativeFromEncoders(mixed0, mixed);
    qDebug() << "Yaw 90 + Pitch 30 test:\n" << eigenToQString(T4);
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    runTests();

    return 0; // no event loop needed for console test
}
