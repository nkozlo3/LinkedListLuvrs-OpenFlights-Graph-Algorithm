// #include "dijkstra.h"

// #include <iostream>
// #include <vector>
// #include <queue>

// // new functions:
// // int Dijkstras::minDist(std::vector<int> distances, std::vector<bool> visited)
// // {
// //     int min = __INT_MAX__;
// //     int idx;
// //     for (size_t i = 0; i < distances.size(); i++)
// //     {
// //         if (distances[i] <= min && !visited[i])
// //         {
// //             min = distances[i];
// //             idx = i;
// //         }
// //     }
// //     return idx;
// // }

// void Dijkstras::dijkstra(std::vector<std::vector<int>> graph, int startVertex)
// {
//     std::vector<int> distances(verteces_.size(), INT_MAX); // min distances for each node

//     distances[startVertex] = 0;  // dist of start vertex to itself = 0

//     std::priority_queue<std::pair<int, Vertex>> priorityQ;
//     // queue of pairs: pair { weight, vertex }

//     std::vector<int> shortestPath(verteces_.size(), 0); // stores previous verteces from a vertex

//     priorityQ.push(std::make_pair(0, startVertex));
    
//     Graph visited;

//     while (!priorityQ.empty()) {
//         Vertex curr = priorityQ.top().second; // gets the next vertex in the queue
//         priorityQ.pop();
//         visited.insertVertex(curr);

//         std::vector<Vertex> adj = getAdjacent(curr);
//         // for neighbors of curr not already visited:
//         for (int i = 0; i < adj.size(); i++) {
//             if (!visited.vertexExists(adj[i])) {
//                 int v = adj[i];
//                 int weight = adj[i]
//                 if (distances[v] > distances[curr] + weight)
//                 {
//                     distances[v] = distances[curr] + weight;
//                     priorityQ.push(std::make_pair(distances[v], v));
//                     shortestPath[v] = curr;
//                 }
//             }
//         }
//     }
//     return shortestPath;
// }
