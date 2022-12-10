#pragma once

#include <iostream>
#include "graph.h"
#include <queue>
class Dijkstras
{
public:
    Dijkstras(Graph g);
    Graph getGraph();
    std::vector<std::string> dijkstra(Graph graph, std::string start, std::string dest);

private:
    Graph g_;
    bool isDirectlyConnected(std::string airport1, std::string airport2);
};