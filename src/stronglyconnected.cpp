#include "stronglyconnected.h"

StronglyConnected::StronglyConnected(Graph &graph)
{
    index_ = 0;
    g_ = graph;
    vertices_ = g_.getAirports();
}

void StronglyConnected::tarjan()
{
    for (size_t i = 0; i < vertices_.size(); i++)
    {
        std::vector<Graph::airport> tempVect;
        if (!vertices_.at(i).visited)
        {
            directConnect(vertices_[i]);
        }
    }
}

void StronglyConnected::directConnect(Graph::airport &vertex)
{
    // set the depth index for vertex to the smallest unused index
    vertex.index = index_;
    vertex.lowLink = index_;
    index_++;
    vertex.onStack = true;
    vertex.visited = true;
    stack_.push(vertex);

    // TODO: RIGHT NOW WHENEVER WE GET THE ADJACENT NODES, WE ARE NOT GETTING THE UPDATED VERSION OF THE NODES. I.E. INSTEAD OF NODE.INDEX = 0, WE GET NODE.INDEX = -1 STILL
    std::vector<Graph::airport> adjNodes = g_.getAdjacentNodes(vertex.airportCode); // get connected nodes

    // Consider successors of v
    for (size_t i = 0; i < adjNodes.size(); i++)
    {
        Graph::airport vertexSuccessor = adjNodes.at(i);

        if (!vertexSuccessor.visited)
        {
            // Successor w has not yet been visited; recurse on
            directConnect(vertexSuccessor);
            vertex.lowLink = std::min(vertex.lowLink, vertexSuccessor.lowLink);
        }
        else if (vertexSuccessor.onStack)
        {
            // Successor w is in stack S and hence in the current SCC
            // If w is not on stack, then (v, w) is an edge pointing to an SCC already found and must be ignored
            vertex.lowLink = std::min(vertex.lowLink, vertexSuccessor.index);
        }
        // If v is a root node, pop the stack and generate an SCC
        if (vertex.lowLink == vertex.index)
        {
            std::vector<Graph::airport> currScc;
            while (vertexSuccessor != vertex)
            {
                vertexSuccessor = stack_.top();
                stack_.pop();
                currScc.push_back(vertexSuccessor);
                vertexSuccessor.onStack = false;
            }
            connected_components_.push_back(currScc);
        }
    }
}

std::vector<Graph::airport> StronglyConnected::getVertices()
{
    return vertices_;
}

std::vector<std::vector<Graph::airport>> StronglyConnected::getConnectedComponents()
{
    return connected_components_;
}