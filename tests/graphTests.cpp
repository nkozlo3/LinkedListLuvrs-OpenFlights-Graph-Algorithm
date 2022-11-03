#include <catch2/catch_test_macros.hpp>

#include "graph.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

TEST_CASE("Graph csvToVect returns a vector of the right width and length", "[weight=1][graph][7]")
{
    Graph graph = Graph();
    std::vector<std::string> widthVect = graph.csvToVect("routes.csv")[0];
    std::vector<std::vector<std::string>> heightVect = graph.csvToVect("routes.csv");

    size_t width = widthVect.size();
    size_t height = heightVect.size();

    REQUIRE(height == 67663);
    REQUIRE(width == 9);
}

TEST_CASE("Graph csvToVect properly maps vectors", "[weight=5][graph][7]")
{
    Graph graph = Graph();
    std::vector<std::vector<std::string>> vect = graph.csvToVect("routes.csv");
    std::vector<std::string> vectAtZero;
    vectAtZero.push_back("2B");
    vectAtZero.push_back("410");
    vectAtZero.push_back("AER");
    vectAtZero.push_back("2965");
    vectAtZero.push_back("KZN");
    vectAtZero.push_back("2990");
    vectAtZero.push_back("0");
    vectAtZero.push_back("CR2");
    std::string expected = "";
    std::string actual = "";
    for (size_t i = 0; i < vectAtZero.size(); i++)
    {
        expected += vectAtZero.at(i);
    }
    for (size_t i = 0; i < vect[0].size(); i++)
    {
        actual += vect[0].at(i);
    }

    REQUIRE(vect[0][0] == "2B");
    REQUIRE(vect[0][1] == "410");
    REQUIRE(vect[3][3] == "2968");
    REQUIRE(actual == expected);
}

TEST_CASE("Graph codeToName returns a map with the right values and keys", "[weight=10][graph][7]")
{
    Graph graph = Graph();
    std::map<std::string, std::string> m = graph.codeToName("Codes.txt");

    REQUIRE(m["ZSJ"] == "Sandy Lake Airport");
    REQUIRE(m["YZZ"] == "Trail Airport");
    REQUIRE(m["YWG"] == "Winnipeg / James Armstrong Richar.");
    REQUIRE(m["2B"] == "Aerocondor");
    REQUIRE(m["DX"] == "DAT Danish Air Transport");
}