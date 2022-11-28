#include <catch2/catch_test_macros.hpp>

#include "graph.h"
#include "dijkstra.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
//PNG png;

Graph g(1, 1, "mercator🤠.png");
TEST_CASE("Dijkstra's returns a correct shortes path", "[weight=1][dijkstra][9]")
{
    Dijkstras d = Dijkstras(g);
    std::vector<std::string> result = d.dijkstra(g, "CHI", "SYD");
    
    REQUIRE(result[0] == "CHI");
    REQUIRE(result[result.size()-1] == "SYD");

    for (std::string s : result) {
        std::cout<< s <<std::endl;
    }
}