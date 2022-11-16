void DFS::dfs() {
    flight_path.clear();
    visited.clear();
    std::unordered_map<std::string, std::unordered_map<std::string, edge>> graph = getAdjacanceMatrix();
    for (auto i : graph) {
        dfs(i.first);
    }
}

void DFS::dfs(std::string airport) {
    std::vector<std::string> end_airport;
    if (visited.find(airport) != visited.end()) {
        return;
    }
    flight_path.push_back(airport);
    visited.insert(airport);
    std::unordered_map<std::string, std::unordered_map<std::string, edge>> graph = getAdjacanceMatrix();
    for (auto i : graph[airport]) {
        end_airport.push_back(i.first);
    }
    for (size_t i = 0; i < graph[airport].size(); i++) {
        dfs(end_airport[i]);
    }
}