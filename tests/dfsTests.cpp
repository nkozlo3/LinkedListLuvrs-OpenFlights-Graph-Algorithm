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

    REQUIRE(d.getFlightPath()[12] == "PRC");
    REQUIRE(d.getFlightPath()[137] == "MGW");
    REQUIRE(d.getFlightPath()[710] == "ATQ");
    REQUIRE(d.getFlightPath()[988] == "COR");
    REQUIRE(d.getFlightPath()[1736] == "NGB");
    REQUIRE(d.getFlightPath()[2285] == "YXY");
    REQUIRE(d.getFlightPath()[2467] == "AFL");
    REQUIRE(d.getFlightPath()[2891] == "PSC");
    REQUIRE(d.getFlightPath()[3248] == "MOL");
}