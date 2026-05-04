#ifndef POSITION_H
#define POSITION_H

struct Position {
    double x{0.0};
    double y{0.0};
    double z{0.0};
    double roll{0.0};   // rotation around X axis
    double pitch{0.0};  // rotation around Y axis
    double yaw{0.0};    // rotation around Z axis
};

#endif // POSITION_H
