#pragma once
#include "types/node.h"
#include "types/edge.h"

struct PoseGraph {
    std::vector<Node> nodes;
    std::vector<Edge> edges;
};
