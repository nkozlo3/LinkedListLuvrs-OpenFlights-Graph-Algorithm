#include <iostream>
#include "graph.h"
#include "cs225/PNG.h"

using namespace cs225;

int main()
{

    std::cout << "Howdy World! 🤠 " << std::endl;

    Graph g(1, 1, 1, "mainGraph", "mercator🤠.png");

    std::pair<double, double> h1h2 = std::make_pair(0, 300);
    std::pair<double, double> s1s2 = std::make_pair(1, 1);
    std::pair<double, double> l1l2 = std::make_pair(.5, .5);
    int xNodeSize = 2;
    int yNodeSize = 2;
    std::string newFileName = "../ybab";

    g.drawGraphOnPNG(h1h2, s1s2, l1l2, xNodeSize, yNodeSize, newFileName, true, true);

    return 0;
}