#pragma once

#include <iostream>
#include "graph.h"
#include <queue>
class Dijkstras
{
public:
    Dijkstras();      // TODO:
    Graph getGraph(); // TODO:
    int minDist(std::vector<int> distances, std::vector<bool> visited);
    std::unordered_map<std::string, double> dijkstra(Graph graph, std::string startVertex);

private:
    Graph g_;
};