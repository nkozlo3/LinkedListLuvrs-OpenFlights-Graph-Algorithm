#pragma once

#include <iostream>
#include "graph.h"
#include <set>

class DFS : public Graph
{
public:
    DFS();
    void dfs();                          // TODO:
    void dfs(std::string airport);  // TODO:
    void dfsToFile();
    std::vector<std::string> getFlightPath();

private:
    std::vector<std::string> flight_path;
    std::set<std::string> visited;
};