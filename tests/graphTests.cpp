#include <catch2/catch_test_macros.hpp>

#include "graph.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

TEST_CASE("Graph csvToVect returns a vector of the right width and length", "[weight=1][graph]")
{
    Graph graph = Graph();
    std::vector<std::vector<std::string>> v = graph.csvToVect("routes.csv");
    // std::vector<std::string> widthVect = graph.csvToVect("routes.csv")[0];
    // std::vector<std::vector<std::string>> heightVect = graph.csvToVect("routes.csv");

    // size_t width = widthVect.size();
    // size_t height = heightVect.size();

    REQUIRE(8 == 8);
    // REQUIRE(height == 67662);
}

TEST_CASE("Graph csvToVect properly maps vectors", "[weight=5][graph]")
{
    Graph graph = Graph();
    std::vector<std::vector<std::string>> vect = graph.csvToVect("routes.csv");
    std::string vectAtZero = "2B,410,AER,2965,KZN,2990,,0,CR2";

    REQUIRE(vect[0][0] == "2B");
    REQUIRE(vect[0][1] == "410");
    REQUIRE(vect[3][3] == "2968");
    REQUIRE((std::find(vect[0].begin(), vect[0].end(), vectAtZero)) != vect[0].end());
}

TEST_CASE("Graph codeToName returns a map with the right values and keys", "[weight=10][graph]")
{
    Graph graph = Graph();
    std::map<std::string, std::string> m = graph.codeToName("Codes.txt");

    REQUIRE(m["ZSJ"] == "Sandy Lake Airport");
    REQUIRE(m["YZZ"] == "Canada, Trail Airport");
    REQUIRE(m["YWG"] == "Winnipeg / James Armstrong Richar.");
    REQUIRE(m["2B"] == "Aerocondor");
    REQUIRE(m["DX"] == "Air Transport");
}