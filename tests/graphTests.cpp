#include <catch2/catch_test_macros.hpp>

#include "graph.h"

TEST_CASE("Graph csvToVect returns a vector of the right width and length", "[weight=1][graph]")
{
    Graph graph = Graph();
    std::vector<std::string> widthVect = graph.csvToVect("routes.csv")[0];
    std::vector<std::vector<std::string>> heightVect = graph.csvToVect("routes.csv");

    size_t width = widthVect.size();
    size_t height = heightVect.size();

    REQUIRE(width == 8);
    REQUIRE(height == 67662);
}
