#include "stronglyconnected.h"

StronglyConnected::StronglyConnected(Graph graph)
{
    index_ = 0;
    g_ = graph;
    vertices_ = g_.getAirports();
}

std::vector<Graph::airport> StronglyConnected::getVertices()
{
    return vertices_;
}

std::vector<std::vector<Graph::airport>> StronglyConnected::tarjan()
{
    std::vector<std::vector<Graph::airport>> connectedComponents;
    for (size_t i = 0; i < vertices_.size(); i++)
    {
        std::vector<Graph::airport> tempVect;
        if (vertices_.at(i).index == -1)
        {
            tempVect = directConnect(vertices_[i]);
        }
        connectedComponents.push_back(tempVect);
    }
    return connectedComponents;
}

std::vector<Graph::airport> StronglyConnected::directConnect(Graph::airport vertex)
{
    // the vector of components strongly connected to vertex
    std::vector<Graph::airport> currScc;
    // set the depth index for vertex to the smallest unused index
    vertex.index = index_;
    vertex.lowLink = index_;
    index_++;
    stack_.push(vertex);
    vertex.onStack = true;

    std::vector<std::string> adjNodes = g_.getAdjacentNodes(vertex.airportCode); // get connected nodes
    std::map<std::string, Graph::airport> airpMap = g_.getAirportsMap();         // getting map from airport code to airport struct

    // Consider successors of v
    for (size_t i = 0; i < adjNodes.size(); i++)
    {
        Graph::airport vertexSuccessor = airpMap[adjNodes.at(i)];

        if (vertexSuccessor.index == -1)
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
            while (vertexSuccessor != vertex)
            {
                currScc.push_back(vertexSuccessor);
                vertexSuccessor = stack_.top();
                stack_.pop();
                vertexSuccessor.onStack = false;
            }
        }
    }
    return currScc;
}