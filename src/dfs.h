#pragma once

#include <iostream>
#include "graph.h"
#include <set>

class DFS : public Graph
{
public:
    void dfs();                          // TODO:
    void dfs(std::string airport);  // TODO:
    void dfsToFile();
    // void fileToVect();
    ~DFS();                         // TODO:
    std::vector<std::string> flight_path;
    std::set<std::string> visited;

private:
};