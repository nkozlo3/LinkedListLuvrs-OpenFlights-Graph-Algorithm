#include "dijkstra.h"

#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>


// new functions:
// int Dijkstras::minDist(std::vector<int> distances, std::vector<bool> visited)
// {
//     int min = __INT_MAX__;
//     int idx;
//     for (size_t i = 0; i < distances.size(); i++)
//     {
//         if (distances[i] <= min && !visited[i])
//         {
//             min = distances[i];
//             idx = i;
//         }
//     }
//     return idx;
// }


std::unordered_map<std::string, double> Dijkstras::dijkstra(Graph graph, std::string startVertex) {   //getedges = returns edge between two nodes
    std::vector<std::string> verteces_ = graph.getVertices();
    //returns a vector of strings of airport codes    
    std::unordered_map<std::string, double> distances;  // stores minimum distances from start

    std::unordered_map<std::string, std::string> predecesor;
    //map of predecesor of vertex -> vertex
   
    for (std::string s : verteces_) {
        distances[s] = __INT_MAX__; //initialize distances as infinity
        predecesor[s] = "";
    }
    distances[startVertex] = 0; //dist of start vertex to itself = 0

    std::priority_queue<std::string> priorityQ;

    priorityQ.push(startVertex);
    
    std::vector<std::string> visited;   //list of the visited airport codes

    //second map is the adjacency list of the first (adj nodes)
    std::unordered_map<std::string, std::unordered_map<std::string, Graph::edge>> adjmap = graph.getAdjacanceMatrix();

    while (!priorityQ.empty()) {
        std::string curr = priorityQ.top(); // gets the next vertex in the queue
        priorityQ.pop();
        visited.push_back(curr);            //add curr to visited

        std::unordered_map<std::string, Graph::edge> adj = adjmap[curr]; 
        //adj is a reference to a map of curr's adj nodes -> distance from curr to each one.

        // for neighbors of curr...
        for (auto it = adj.begin(); it != adj.end(); ++it) {
            if (!(std::find(visited.begin(), visited.end(), curr) != visited.end())) { //if not visited
                std::string adjAirport = it->first;
                Graph::edge e = adj[adjAirport]; //if e's weight < known dist, update shortest dist
                if (e.distance_edgeWeight + distances[curr] < distances[adjAirport])  
                //if cost(u, v) + d[u] < d[v]:
                // distance_edgeWeight is distance between two airports
                //if dist of vertex > dist of current + weight
                { 
                    distances[adjAirport] = distances[curr] + e.distance_edgeWeight;
                    priorityQ.push(adjAirport);
                    //push the neighbor to queue
                    predecesor[adjAirport] = curr;
                }
            }
        }
    }
    return distances;
}
