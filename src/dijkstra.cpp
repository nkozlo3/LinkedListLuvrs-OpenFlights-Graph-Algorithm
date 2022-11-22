#include "dijkstra.h"

Dijkstras::Dijkstras(Graph g)
{
    g_ = g;
}

Graph Dijkstras::getGraph() {
    return g_;
}

std::vector<std::string> Dijkstras::dijkstra(Graph graph, std::string start, std::string dest)
{  //path we will return:
    std::vector<std::string> path;
    //base cases:
    if (start == dest) {
        path.push_back(start);
        return path;
    }

    if ((graph.getAdjacencyListEdge(start, dest)).destAirportCode_destVertex != "//N") {
        path.push_back(start);
        path.push_back(dest);
        return path;
    }
    // getedges = returns edge between two nodes
    std::vector<std::string> verteces_ = graph.getVertices();
    // returns a vector of strings of airport codes

    std::unordered_map<std::string, double> distances(verteces_.size()); 
    //distances = distances to get to the start vertex from each node
    // stores minimum distances from start. vertex -> dist
    
    std::unordered_map<std::string, std::string> predecesor(verteces_.size());
    //maps preceeding airport -> current airport (the one we encountered before it)

    std::priority_queue<std::string> priorityQ;

    for (std::string s : verteces_) {
        distances[s] = __INT_MAX__; // initialize distances as infinity
        predecesor[s] = "";
        priorityQ.push(s);
    }
    distances[start] = 0; // dist of start vertex to itself = 0

    //std::vector<std::string> visited; // list of the visited airport codes
    // second map is the adjacency list of the first (adj nodes)
    while (!priorityQ.empty())
    {
        std::string curr = priorityQ.top(); // gets the next vertex in the queue
        priorityQ.pop();
        if (curr == dest) {
            if (curr == start || predecesor[curr] != "") {
              //  double d = 0.0;
                while (predecesor[curr] != start) {
                    path.push_back(curr);
                    std::string prev = predecesor[curr];
                  //  d += (graph.getAdjacencyListEdge(curr, prev)).distance_edgeWeight;
                    curr = prev;
                }
                path.push_back(curr);
             //   d += (graph.getAdjacencyListEdge(curr, start)).distance_edgeWeight;
                path.push_back(start);
                std::reverse(path.begin(), path.end());
                return path;
            }
        }
        // adj is a map of curr's adj nodes -> distance from curr to each one.
        if (distances[curr] < __INT_MAX__) {
            std::unordered_map<std::string, Graph::pairOfAirports> adj = graph.getAdjacentMap(curr);
            // for neighbors of curr...
            for (auto it = adj.begin(); it != adj.end(); ++it)
            {
                std::string adjAirport = it->first;
                Graph::pairOfAirports e = adj[adjAirport]; // if e's weight < known dist, update shortest dist
                if (e.distance_edgeWeight + distances[curr] < distances[adjAirport])
                // if cost(u, v) + d[u] < d[v]:
                // if dist of vertex > dist of current + weight
                {
                    distances[adjAirport] = distances[curr] + e.distance_edgeWeight;
                    priorityQ.push(adjAirport);
                    // push the neighbor to queue
                    predecesor[adjAirport] = curr;
                }
            }
        } // visited.push_back(curr); // add curr to visited
    }
    // for (std::string s : path) {
    //     std::cout<< s <<std::endl;
    // }
    return path;
}
