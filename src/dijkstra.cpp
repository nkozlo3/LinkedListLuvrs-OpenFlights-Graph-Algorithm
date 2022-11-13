#include "dijkstra.h"

#include <iostream>
#include <vector>
#include <queue>

// new functions:
int Dijkstras::minDist(std::vector<int> distances, std::vector<bool> visited)
{
    int min = __INT_MAX__;
    int idx;
    for (int i = 0; i < distances.size(); i++)
    {
        if (distances[i] <= min && !shortestPathSet[i])
        {
            min = distances[i];
            idx = i;
        }
    }
    return idx;
}

void Dijkstras::dijkstra(std::vector<std::vector<int>> graph, int startVertex)
{
    std::vector<bool> visited;  // keep track of visited vertices
    std::vector<int> distances; // min distances for each node

    distances[startVertex] = 0;  // dist of start vertex to itself = 0
    visited[startVertex] = true; // set current vertex as visited
    std::queue<std::pair<int, int>> priorityQ;

    // queue of pairs: pair { vertex, weight }

    std::vector<int> prevs; // stores previous verteces from a vertex

    for (int i = 0; i < verteces_.size(); i++)
    { // for each vertex in graph
        if (verticies_[i] != startVertex)
        {
            distances[i] = INT_MAX; // dist of all verticies from start = infinity
            prevs[i] = -1;
            visited[i] = false;
        }
    }
    // priority_queue.buildHeap(graph.verticies());
    priorityQ.push(std::make_pair(distances[startVertex], startVertex));

    while (!priorityQ.empty())
    {
        int curr = priorityQ.top().second; // gets the next vertex in the queue
        priorityQ.pop();

        // for neighbors of curr not already visited:
        for (auto pair : adj[curr])
        {
            if (!visited[curr])
            {
                if (distances[pair.first] > distances[curr] + pair.second)
                {
                    distances[pair.first] = distances[curr] + pair.second;
                    // priorityQ.push(std::make_pair(distances[pair.first], pair.first));
                    prevs[pair.second] = curr;
                }
            }
        }
        visited[curr] = true;
    }
}