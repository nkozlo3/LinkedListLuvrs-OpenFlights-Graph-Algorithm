void DFS::DFS() {
    flight_path.clear();
    visited.clear();

}

void DFS::DFS(std::string airport) {
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