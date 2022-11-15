#include <iostream>
#include "graph.h"
#include "cs225/PNG.h"

using namespace cs225;

int main()
{
    Graph g(1, 1, 1, "mainGraph");

    std::cout << "Howdy World! 🤠 " << std::endl;

    PNG png;

    g.drawGraphOnPNG("mercator🤠", png, 0, 1, 0.5, 2, 2, "../baby");


    std::cout << png.width() << "  ::  " << png.height() << std::endl;
    return 0;
}