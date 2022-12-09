#include <catch2/catch_test_macros.hpp>

#include "graph.h"
#include "dfs.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

TEST_CASE("DFS returns correct size", "[weight=1][dfs][11]") 
{
    Graph graph(1, 1, "mercator🤠.png");
    DFS d;
    d.dfs();

    size_t size = d.getFlightPath().size();
    size_t airport_size = graph.getAdjacanceMatrix().size();

    REQUIRE(size == airport_size);
}

TEST_CASE("DFS returns correct starting airport", "[weight=1][dfs][11]") 
{
    Graph graph(1, 1, "mercator🤠.png");
    DFS d;
    d.dfs();

    std::string starting = d.getFlightPath()[0];

    REQUIRE(starting == "TRO");
}

TEST_CASE("DFS returns correct ending airport", "[weight=1][dfs][11]") 
{
    Graph graph(1, 1, "mercator🤠.png");
    DFS d;
    d.dfs();

    std::string ending = d.getFlightPath()[d.getFlightPath().size() - 1];

    REQUIRE(ending == "JEG");
}

TEST_CASE("Testing random airports with adjacency list", "[weight=1][dfs][11]") 
{
    Graph graph(1, 1, "mercator🤠.png");
    DFS d;
    d.dfs();

    // for (size_t i = 0; i < graph.getAirportList().size(); i++) {
    //     for (size_t i = 0; i < d.getFlightPath().size(); i++) {
    //         std::string airport = graph.getAirportList()[i];
    //         std::string dfs_airport = d.getFlightPath()[i];
    //         REQUIRE(airport == dfs_airport);
    //     }
    // }

    REQUIRE(d.getFlightPath()[12] == "PRC");
    REQUIRE(d.getAirportList()[12] == "PRC");
}