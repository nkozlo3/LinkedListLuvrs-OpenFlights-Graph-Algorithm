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

    double expected = 250;

    REQUIRE(actual == expected);
}

TEST_CASE("Graph sourceToDestLongLat outputs correct data", "[weight=5][graph][7]")
{
    Graph graph = Graph();

    std::map<std::string, std::vector<Graph::edge>> m = graph.sourceToDestLongLat("routes.csv");

    std::map<std::string, std::pair<double, double>> m1 = graph.codeToPosition("airports.csv");

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

    REQUIRE(m[str[0]].at(0).sourceAirportCode_sourceVertex == "AMD");
    REQUIRE(m[str[0]].at(1).sourceAirportCode_sourceVertex == "BLR");
    REQUIRE(m[str[0]].at(2).sourceAirportCode_sourceVertex == "BOM");
    REQUIRE(m[str[0]].at(3).sourceAirportCode_sourceVertex == "CCJ");
    REQUIRE(m[str[0]].at(4).sourceAirportCode_sourceVertex == "COK");
    REQUIRE(m[str[0]].at(5).sourceAirportCode_sourceVertex == "DEL");
    REQUIRE(m[str[0]].at(6).sourceAirportCode_sourceVertex == "DMM");
    REQUIRE(m[str[0]].at(7).sourceAirportCode_sourceVertex == "HYD");
    REQUIRE(m[str[0]].at(8).sourceAirportCode_sourceVertex == "KWI");
    REQUIRE(m[str[0]].at(9).sourceAirportCode_sourceVertex == "MAA");
    REQUIRE(m[str[0]].at(10).sourceAirportCode_sourceVertex == "TRV");
    REQUIRE(m[str[0]].at(11).sourceAirportCode_sourceVertex == "ATH");
    REQUIRE(m[str[0]].at(12).sourceAirportCode_sourceVertex == "CMB");
    REQUIRE(m[str[0]].at(13).sourceAirportCode_sourceVertex == "DUS");

    for (size_t i = 0; i < str.size(); i++)
    {
        std::string dest = m[str[i]].at(0).sourceAirportCode_sourceVertex;

        for (size_t j = 0; j < m[str[i]].size(); j++)
        {
            std::string dest = m[str[i]].at(j).sourceAirportCode_sourceVertex;
            REQUIRE(m[str[i]][j].lonAndLatPoints.first == m1[dest].first);
            REQUIRE(m[str[i]][j].lonAndLatPoints.second == m1[dest].second);
            REQUIRE(m[str[i]][j].distance == graph.sourceToDestLongLatHelper(m1[str[i]].first, m1[str[i]].second, m1[dest].first, m1[dest].second));
        }

        REQUIRE(m[str[i]].at(0).lonAndLatPoints.first == m1[dest].first);
        REQUIRE(m[str[i]].at(0).lonAndLatPoints.second == m1[dest].second);
        REQUIRE(m[str[i]].at(0).distance == graph.sourceToDestLongLatHelper(m1[str[i]].first, m1[str[i]].second, m1[dest].first, m1[dest].second));
    }
}

TEST_CASE("Graph codeToPosition contains longitudes and latitudes", "[weight=5][graph][7]")
{
    Graph graph = Graph();

    std::map<std::string, std::pair<double, double>> m = graph.codeToPosition("airports.csv");

    double actual1 = m["GKA"].first;
    double actual2 = m["GKA"].second;
    double actual3 = m["AER"].first;
    double actual4 = m["AER"].second;

    double expected3 = 43.449902;
    double expected4 = 39.9566;

    double expected1 = -6.081689834590001;
    double expected2 = 145.391998291;

    REQUIRE(actual1 == expected1);
    REQUIRE(actual2 == expected2);
    REQUIRE(actual3 == expected3);
    REQUIRE(actual4 == expected4);
}