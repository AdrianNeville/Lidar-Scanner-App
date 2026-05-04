#pragma once
#include "constants.h"
#include <QtMath>
#include <QDebug>

struct Pose {
    double x;
    double y;
    double z;
    double pitch;
    double yaw;

    // constructor
    Pose(double x_, double y_, double z_, double pitch_, double yaw_)
        : x(x_), y(y_), z(z_), pitch(pitch_), yaw(yaw_) {}

    // default constructor
    Pose() : x(0.0), y(0.0), z(0.0), pitch(0.0), yaw(0.0) {

    }

    Pose(double elev, double azim)
        : pitch(elev), yaw(azim) {
        y = Y_OFFSET*cos((M_PI/180.0)*elev);
        z = Y_OFFSET*sin((M_PI/180.0)*elev)*cos((M_PI/180.0)*azim);
        x = Y_OFFSET*sin((M_PI/180.0)*elev)*sin((M_PI/180.0)*azim);

        x/=VERT_SCALE;
        y/=VERT_SCALE;
        z/=VERT_SCALE;

        qDebug() << "From Pose Struct:" << x << ", " << y << ", " << z;
    }
};
