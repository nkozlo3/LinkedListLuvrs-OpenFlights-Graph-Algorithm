#pragma once

#include <iostream>
#include "graph.h"
#include "dfs.h"
#include <set>
#include <stack>

class StronglyConnected
{
public:
    StronglyConnected(Graph graph);            // TODO:
    void tarjan();                             // TODO:
    void directConnect(Graph::airport vertex); // TODO:
    std::vector<Graph::airport> getVertices();
    std::vector<std::vector<Graph::airport>> getConnectedComponents();

private:
    Graph g_;
    std::vector<Graph::airport> vertices_;
    std::vector<std::vector<Graph::airport>> connected_components_;
    std::stack<Graph::airport> stack_;
    int index_;
};