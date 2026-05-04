#pragma once
#include "types/pose.h"

struct Node {
    int id;             // unique index in the pose graph
    Pose pose;          // your pose struct
    bool fixed{false};  // e.g., first node is fixed as world origin
};
