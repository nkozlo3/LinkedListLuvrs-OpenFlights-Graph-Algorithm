#pragma once

#include <iostream>
#include "graph.h"
class DFS : public Graph
{
public:
    void DFS();                          // TODO:
    void DFS(std::string airport);  // TODO:
    ~DFS();                         // TODO:
    std::vector<std::string> flight_path;
    std::set<std::string> visited;

private:
};