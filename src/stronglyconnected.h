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
    std::vector<std::vector<Graph::airport>> tarjan();          // TODO:
    std::vector<Graph::airport> directConnect(Graph::airport vertex); // TODO:
    std::vector<Graph::airport> getVertices();


private:
    Graph g_;
    std::vector<Graph::airport> vertices_;
    std::stack<Graph::airport> stack_;
    int index_;
};