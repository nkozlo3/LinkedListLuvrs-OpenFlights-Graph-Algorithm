#include "dijkstra.h"

Dijkstras::Dijkstras(Graph g)
{
    g_ = g;
}

Graph Dijkstras::getGraph() {
    return g_;
}

bool Dijkstras::isDirectlyConnected(std::string airport1, std::string airport2) {
    std::vector<Graph::airport> direct_connections = g_.getAdjacentNodes(airport1); //direct connetions of starting airport
    for (Graph::airport a : direct_connections) {
        if (a.airportCode == airport2) {
            return true;
        }
    }
    return false;
}
std::vector<std::string> Dijkstras::dijkstra(Graph graph, std::string start, std::string dest)
{  //path we will return:
    std::vector<std::string> path;
    if (isDirectlyConnected(start, dest)) {
        path.push_back(start);
        path.push_back(dest);
        return path;
    }
    std::vector<std::string> verteces_ = graph.getVertices();  //vector of strings of airport codes

    std::unordered_map<std::string, double> distances(verteces_.size());
    //stores minimum distances to get to start from each node. string vertex -> double dist
    
    std::unordered_map<std::string, std::string> predecesor(verteces_.size());
    //maps preceeding airport -> current airport (the one we encountered before it)

    std::priority_queue<std::string> priorityQ;

    std::vector<std::string> visited;  // list of the visited airport codes

    for (std::string s : verteces_) {
        distances[s] = __INT_MAX__; // initialize distances as infinity
        predecesor[s] = "";
    }
    distances[start] = 0; // dist of start vertex to itself = 0
    priorityQ.push(start);

    while (!priorityQ.empty())
    {
        std::string curr = priorityQ.top(); // gets the next vertex in the queue
        priorityQ.pop();
        if (curr == dest) { break; }
        // adj is a map of curr's adj nodes -> distance from curr to each one.
        std::unordered_map<std::string, Graph::pairOfAirports> adj = graph.getAdjacentMap(curr);
        
        // for neighbors of curr...
        for (auto it = adj.begin(); it != adj.end(); ++it) {
            std::string adjAirport = it->first;
            Graph::pairOfAirports e = it->second; 
            // if adj's edge weight < known dist && adj !visited, update shortest dist
            if (std::find(visited.begin(), visited.end(), adjAirport) == visited.end() &&
            std::find(visited.begin(), visited.end(), curr) == visited.end()) {
                if (e.distance_edgeWeight + distances[curr] < distances[adjAirport]) {
                    // if cost(u, v) + d[u] < d[v]:
                    // if dist of vertex > dist of current + weight
                    distances[adjAirport] = distances[curr] + e.distance_edgeWeight;
                    predecesor[adjAirport] = curr;
                    priorityQ.push(adjAirport);
                }
            }  
        }
        visited.push_back(curr); //curr has now been visited
    }
    std::string temp = dest;
    path.push_back(dest);
    
    //while we haven't reached the start, backtrack and add each preceding node to final path
    while (temp != start) {
        path.push_back(predecesor[temp]); 
        temp = predecesor[temp];   // "increments" temp
    }
    std::reverse(path.begin(), path.end()); //must reverse since it will be in backwards order
    if (path.empty()) {
        std::cout<<"No path between "<<start<<" and "<<dest<<" exists."<<std::endl;
        return path;
    }
    return path;
}


