#include <catch2/catch_test_macros.hpp>

#include "graph.h"
#include "dfs.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

Graph g(1, 1, "mercator🤠.png");
TEST_CASE("DFS returns correct size", "[weight=1][dfs][11]") 
{
    size_t size = flight_path.size();
    size_t airport_size = graph.getAirports().size();

    REQUIRE(size == airport_size);
}