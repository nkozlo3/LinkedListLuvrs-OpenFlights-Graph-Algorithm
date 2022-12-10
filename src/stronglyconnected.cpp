#include "stronglyconnected.h"

// Tarjans algorithm wiki: https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm

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
            vertices_.at(i).visited = true;
            vertices_.at(i).onStack = true;
            vertices_.at(i).index = index_;
            vertices_.at(i).lowLink = index_;
            directConnect(vertices_[i]);
        }
    }
}

void StronglyConnected::directConnect(Graph::airport &vertex)
{
    // set the depth index for vertex to the smallest unused index
    vertex.onStack = true;
    vertex.visited = true;
    vertex.index = index_;
    vertex.lowLink = index_;
    index_++;
    stack_.push(vertex);

    // set the airport at vertex.airportCode using the setAirport function from the graph class
    g_.setAirport(vertex.airportCode, vertex.index, vertex.lowLink, vertex.onStack, vertex.visited);

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
            do
            {
                vertexSuccessor = stack_.top();
                stack_.pop();
                vertexSuccessor.onStack = false;
                // if (!vertexSuccessor.airportCode.empty())
                // {
                //     vertexSuccessor.airportCode = "self connection?"; // TODO: verify this
                // }
                currScc.push_back(vertexSuccessor);
                if (vertexSuccessor.airportCode == vertex.airportCode) {
                    break;
                }
            } while (vertexSuccessor != vertex && !stack_.empty());
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

Graph StronglyConnected::getGraph()
{
    return g_;
}