#include <catch2/catch_test_macros.hpp>

#include "graph.h"
#include "dijkstra.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

Graph g(1, 1, "mercator🤠.png");
Dijkstras d = Dijkstras(g);

TEST_CASE("Dijkstra's returns a correct shortest path", "[weight=1][dijkstra][9]")
{
    std::vector<std::string> result = d.dijkstra(g, "DBA", "SYD");
    
    REQUIRE(!result.empty());
    REQUIRE(result[0] == "DBA");
    REQUIRE(result[result.size()-1] == "SYD");

    for (std::string s : result) {
        std::cout<< s <<std::endl;
    }
}

TEST_CASE("Dijkstra's returns a correct shortest path test 2", "[weight=1][dijkstra][9]")
{
    std::vector<std::string> result = d.dijkstra(g, "SEA", "PEK");
    
    REQUIRE(!result.empty());
    REQUIRE(result[0] == "SEA");
    REQUIRE(result[result.size()-1] == "PEK");

    for (std::string s : result) {
        std::cout<< s <<std::endl;
    }
}

TEST_CASE("Dijkstra's returns empty if no path exists", "[weight=1][dijkstra][9]")
{
    std::vector<std::string> result = d.dijkstra(g, "XEQ", "QJH");
    
    REQUIRE(result.size() == 0);
}

TEST_CASE("Dijkstra's returns only the 2 airports if directly connected", "[weight=1][dijkstra][9]")
{
    std::vector<std::string> result = d.dijkstra(g, "DXB", "PZU");
    
    REQUIRE(result.size() == 2);
    REQUIRE(result[0] == "DXB");
    REQUIRE(result[result.size()-1] == "PZU");

    for (std::string s : result) {
        std::cout<< s <<std::endl;
    }
}