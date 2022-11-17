#include <iostream>
#include "graph.h"
#include "cs225/PNG.h"

using namespace cs225;

int main()
{

    std::cout << "Howdy World! 🤠 " << std::endl;

    // Graph g(1, 1, 1, "mainGraph", "mercator🤠.png");
    Graph g1(1, 1, 1, "mainGraph", "mercator🤠.png");

    std::pair<double, double> h1h2 = std::make_pair(0, 300);
    std::pair<double, double> s1s2 = std::make_pair(1, 1);
    std::pair<double, double> l1l2 = std::make_pair(.5, .5);
    int xNodeSize = 2;
    int yNodeSize = 2;
    std::string newFileNameBoth = "../sad";
    std::string newFileNameNodes = "../baby";

    // g.drawGraphOnPNG(h1h2, s1s2, l1l2, xNodeSize, yNodeSize, newFileNameBoth, true, true);
    g1.drawGraphOnPNG(h1h2, s1s2, l1l2, xNodeSize, yNodeSize, newFileNameNodes, true, true);

    std::pair<double, double> points0 = g1.getPixelPoints().at("BTI");
    std::pair<double, double> points1 = g1.getPixelPoints().at("GRY");

    std::pair<double, double> nodes0 = g1.getNodePositions().at("BTI");
    std::pair<double, double> nodes1 = g1.getNodePositions().at("GRY");

    PNG png;
    png.readFromFile("../baby.png");

    std::cout << "Location of points1 first: " << points1.first << " second: " << points1.second << std::endl;

    png.drawLine(png.width() / 2, png.height() / 2, (int)points1.first, (int)points1.second, h1h2.second, s1s2.second, l1l2.second);
    png.drawLine((int)points0.first, (int)points0.second, (int)points1.first, (int)points1.second, h1h2.second, s1s2.second, l1l2.second);

    png.writeToFile("../lineHopefully.png");

    return 0;
}