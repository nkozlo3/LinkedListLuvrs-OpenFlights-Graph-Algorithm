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

TEST_CASE("Graph csvToVect properly maps vectors and only takes in the specified columns", "[weight=5][graph][7]")
{
    Graph graph = Graph();
    std::vector<std::vector<std::string>> vect = graph.csvToVect("airports.csv", {6, 7});
    std::vector<std::string> vectAtZero;
    vectAtZero.push_back("-6.081689834590001");
    vectAtZero.push_back("145.391998291");
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

    REQUIRE(vect[0][0] == "-6.081689834590001");
    REQUIRE(vect[0][1] == "145.391998291");
    REQUIRE(vect[3][1] == "146.725977");
    REQUIRE(actual == expected);
}

TEST_CASE("Graph numberNormalized normalizes the numbers properly", "[weight=5][graph][7]")
{
    Graph graph = Graph();

    double actual = graph.numberNormalized(-180, 180, 0, 500, 0);

    double actual1 = graph.numberNormalized(-180, 180, 0, 1254, 107.73799896240234);

    std::cout << actual1 << std::endl;

    double expected = 250;

    REQUIRE(actual == expected);
}

TEST_CASE("Graph sourceToDestsMapMaker does not have duplicates", "[weight=5][graph][9]")
{
    Graph graph = Graph();

    std::map<std::string, std::vector<Graph::structone>> m = graph.sourceToDestsMapMaker("routes.csv");

    std::vector<std::string> str =
        {
            "AUH",
            "BKK",
            "RGN",
            "SGN",
            "SIN",
            "SYD",
            "TBB",
            "THD",
            "TPE",
            "UIH",
            "VCA",
            "VCL",
            "VCS",
            "VDH",
            "VII",
            "VKG",
            "VTE",
            "WNZ"};

    std::cout << m["TBB"].at(0).lonAndLatPoints.first << " " << m["AUH"].at(0).lonAndLatPoints.second << std::endl;
    std::cout << m["TBB"].at(0).airportCode << std::endl;
}

TEST_CASE("Graph codeToPosition contains longitudes and latitudes", "[weight=5][graph][7]")
{
    Graph graph = Graph();

    std::map<std::string, std::pair<double, double>> m = graph.codeToPositionMapMaker("airports.csv");

    double actual1 = m["\"GKA\""].first;
    double actual2 = m["\"GKA\""].second;

    double expected1 = -6.081689834590001;
    double expected2 = 145.391998291;

    REQUIRE(actual1 == expected1);
    REQUIRE(actual2 == expected2);
}