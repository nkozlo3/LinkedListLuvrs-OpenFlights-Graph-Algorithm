#include "dfs.h"

DFS::DFS() {}

void DFS::dfs()
{
    flight_path.clear();
    visited.clear();

    // std::cout << flight_path.size() << std::endl;
    // std::cout << visited.size() << std::endl;

    Graph g(1, 1, "mercator🤠.png");
    std::unordered_map<std::string, std::unordered_map<std::string, pairOfAirports>> graph = g.getAdjacanceMatrix();
    // std::cout << graph.size() << std::endl;
    
    for (auto i : graph)
    {
        dfs(i.first);
    }

    // std::cout << flight_path.size() << " end" << std::endl;
    // std::cout << visited.size() << " end" << std::endl;
}

void DFS::dfs(std::string airport)
{
    std::vector<std::string> end_airport;
    // if airport has already been visited
    if (visited.find(airport) != visited.end())
    {
        return;
    }

    // adding each not visited airport to the flight path
    flight_path.push_back(airport);
    visited.insert(airport);

    // Graph g(1, 1, "mercator🤠.png");
    std::unordered_map<std::string, std::unordered_map<std::string, pairOfAirports>> graph = getAdjacanceMatrix();
    for (auto i : graph[airport])
    {
        end_airport.push_back(i.first);
    }

    // search through all destination airports 
    for (size_t i = 0; i < graph[airport].size(); i++)
    {
        if (visited.find(end_airport[i]) == visited.end())
        {
            dfs(end_airport[i]);
        }
    }
}

void DFS::dfsToFile() 
{
    // writing the flight path to file
    // std::cout << "dfs file" << std::endl;
    std::ofstream file("dfs_file.txt");
    for (auto i = flight_path.begin(); i != flight_path.end(); ++i) 
    {
        file << *i << std::endl;
    }
    file.close();
}

std::vector<std::string> DFS::getFlightPath() {
    return flight_path;
}