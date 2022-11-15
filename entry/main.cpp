#include <iostream>
#include "graph.h"
#include "cs225/PNG.h"

using namespace cs225;

int main()
{

    std::cout << "Howdy World! 🤠 " << std::endl;

    Graph g(1, 1, 1, "mainGraph", "mercator🤠.png");
    Graph g1(1, 1, 1, "mainGraph", "mercator🤠.png");

    int newWidth = g.getPng().width() * 3;
    int newHeight = g.getPng().height() * 3;

    g.getPng().resize(newWidth, newHeight);

    int newWidth1 = g1.getPng().width() * 3;
    int newHeight1 = g1.getPng().height() * 3;

    g1.getPng().resize(newWidth1, newHeight1);

    std::pair<double, double> h1h2 = std::make_pair(0, 300);
    std::pair<double, double> s1s2 = std::make_pair(1, 1);
    std::pair<double, double> l1l2 = std::make_pair(.5, .5);
    int xNodeSize = 2;
    int yNodeSize = 2;
    std::string newFileNameBoth = "../sad";
    std::string newFileNameNodes = "../baby";

    g.drawGraphOnPNG(h1h2, s1s2, l1l2, xNodeSize, yNodeSize, newFileNameBoth, true, true);
    g1.drawGraphOnPNG(h1h2, s1s2, l1l2, xNodeSize, yNodeSize, newFileNameNodes, true, false);

    return 0;
}