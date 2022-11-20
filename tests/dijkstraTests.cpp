#include <catch2/catch_test_macros.hpp>

#include "graph.h"
#include "dijkstra.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
//PNG png;


TEST_CASE("Dijkstra's returns a correct shortes path", "[weight=1][graph][7]")
{
    Graph graph(1, 1, 0, "testGraph", "mercator🤠.png");
    Dijkstras d = Dijkstras(graph);

    std::vector<std::string> result = d.dijkstra(graph, "LAX", "SYD");
    
    for (std::string s : result) {
        std::cout<< s <<std::endl;
    }
}