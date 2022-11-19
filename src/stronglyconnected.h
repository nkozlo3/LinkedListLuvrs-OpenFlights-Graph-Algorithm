#pragma once

#include <iostream>
#include "graph.h"
#include "dfs.h"
#include <set>

class StronglyConnected
{
public:
    StronglyConnected(Graph graph);                       // TODO:
    std::set<std::string> directlyConnected(Graph graph); // TODO:

private:
    Graph g_;
};