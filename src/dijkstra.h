#pragma once

#include <iostream>
#include "graph.h"
class Dijkstras
{
public:
    Dijkstras();      // TODO:
    Graph getGraph(); // TODO:
    int minDist(std::vector<int> distances, std::vector<bool> visited);
    void dijkstra(std::vector<std::vector<int>> graph, int startVertex);
private:
};