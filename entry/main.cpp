#include <iostream>
#include "graph.h"
#include "dijkstra.h"
#include "dfs.h"
#include "cs225/PNG.h"

using namespace cs225;

int main()
{

    std::cout << "Howdy World! 🤠 " << std::endl;

    Graph g(1, 1, "mercator🤠.png");
    Dijkstras d(g);

    // beginning of code to create graph
    std::pair<double, double> h1h2 = std::make_pair(0, 300);
    std::pair<double, double> s1s2 = std::make_pair(1, 1);
    std::pair<double, double> l1l2 = std::make_pair(.5, .5);
    std::pair<double, double> a1a2 = std::make_pair(1, .4);
    int xNodeSize = 2;
    int yNodeSize = 2;
    std::string newFileName = "../ybab";

    g.drawGraphOnPNG(h1h2, s1s2, l1l2, xNodeSize, yNodeSize, newFileName, a1a2);
    // end of code to create graph

    // beginning of code to run dijkstras and check shortest distance between two airports
    std::string sourceAirport = "";
    std::string destAirport = "";
    std::string shortestRoute = "";
    std::cout << "Please enter source airport code: " << std::endl;
    std::cin >> sourceAirport;
    std::cout << "Please enter the destination airport code: " << std::endl;
    std::cin >> destAirport;

    std::vector<std::string> shortestDest = d.dijkstra(g, sourceAirport, destAirport);

    for (size_t i = 0; i < shortestDest.size(); i++)
    {
        if (i == 0)
            shortestRoute += "Shortest route between " + sourceAirport + " and " + destAirport + ": " + shortestDest.at(i) + ", ";
        else if (i < shortestDest.size() - 1)
            shortestRoute += shortestDest.at(i) + ", ";
        else
            shortestRoute += shortestDest.at(i);
    }

    std::cout << std::endl;
    std::cout << shortestRoute << std::endl;

    DFS df;
    df.dfs();
    df.dfsToFile();

    return 0;
}