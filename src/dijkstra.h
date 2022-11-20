#pragma once

#include <iostream>
#include "graph.h"
#include <queue>
class Dijkstras
{
public:
    Dijkstras(Graph g);      // TODO:
    Graph getGraph(); // TODO:
    int minDist(std::vector<int> distances, std::vector<bool> visited);
    std::vector<std::string> dijkstra(Graph graph, std::string start, std::string dest);

private:
    Graph g_;
};