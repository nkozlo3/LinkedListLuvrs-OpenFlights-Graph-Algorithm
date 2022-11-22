#include <catch2/catch_test_macros.hpp>

#include "graph.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
Graph graph(1, 1, 0, "testGraph", "mercator🤠.png");

TEST_CASE("Graph csvToVect returns a vector of the right width and length", "[weight=1][graph][7]")
{
    std::vector<std::string> widthVect = graph.csvToVect("routes.csv")[0];
    std::vector<std::vector<std::string>> heightVect = graph.csvToVect("routes.csv");

    size_t width = widthVect.size();
    size_t height = heightVect.size();

    REQUIRE(height == 67663);
    REQUIRE(width == 9);
}

TEST_CASE("Graph csvToVect properly maps vectors", "[weight=5][graph][7]")
{

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

    double actual = graph.numberNormalized(-180, 180, 0, 500, 0);

    double actual1 = graph.numberNormalized(-180, 180, 0, 1254, 107.73799896240234);

    double expected = 250;

    REQUIRE(actual == expected);
}

TEST_CASE("Graph sourceToDestLongLat outputs correct data", "[weight=5][graph][7]")
{

    std::map<std::string, std::vector<Graph::pairOfAirports>> m = graph.sourceToDestLongLat("routes.csv");

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

    REQUIRE(m[str[0]].at(0).sourceAirportCode_sourceVertex == "AUH");
    REQUIRE(m[str[0]].at(1).sourceAirportCode_sourceVertex == "AUH");
    REQUIRE(m[str[0]].at(2).sourceAirportCode_sourceVertex == "AUH");
    REQUIRE(m[str[0]].at(3).sourceAirportCode_sourceVertex == "AUH");
    REQUIRE(m[str[0]].at(4).sourceAirportCode_sourceVertex == "AUH");
    REQUIRE(m[str[0]].at(5).sourceAirportCode_sourceVertex == "AUH");
    REQUIRE(m[str[0]].at(6).sourceAirportCode_sourceVertex == "AUH");
    REQUIRE(m[str[0]].at(7).sourceAirportCode_sourceVertex == "AUH");
    REQUIRE(m[str[0]].at(8).sourceAirportCode_sourceVertex == "AUH");
    REQUIRE(m[str[0]].at(9).sourceAirportCode_sourceVertex == "AUH");
    REQUIRE(m[str[0]].at(10).sourceAirportCode_sourceVertex == "AUH");
    REQUIRE(m[str[0]].at(11).sourceAirportCode_sourceVertex == "AUH");
    REQUIRE(m[str[0]].at(12).sourceAirportCode_sourceVertex == "AUH");
    REQUIRE(m[str[0]].at(13).sourceAirportCode_sourceVertex == "AUH");

    REQUIRE(m[str[0]].at(0).destAirportCode_destVertex == "AMD");
    REQUIRE(m[str[0]].at(1).destAirportCode_destVertex == "BLR");
    REQUIRE(m[str[0]].at(2).destAirportCode_destVertex == "BOM");
    REQUIRE(m[str[0]].at(3).destAirportCode_destVertex == "CCJ");
    REQUIRE(m[str[0]].at(4).destAirportCode_destVertex == "COK");
    REQUIRE(m[str[0]].at(5).destAirportCode_destVertex == "DEL");
    REQUIRE(m[str[0]].at(6).destAirportCode_destVertex == "DMM");
    REQUIRE(m[str[0]].at(7).destAirportCode_destVertex == "HYD");
    REQUIRE(m[str[0]].at(8).destAirportCode_destVertex == "KWI");
    REQUIRE(m[str[0]].at(9).destAirportCode_destVertex == "MAA");
    REQUIRE(m[str[0]].at(10).destAirportCode_destVertex == "TRV");
    REQUIRE(m[str[0]].at(11).destAirportCode_destVertex == "ATH");
    REQUIRE(m[str[0]].at(12).destAirportCode_destVertex == "CMB");
    REQUIRE(m[str[0]].at(13).destAirportCode_destVertex == "DUS");

    for (size_t i = 0; i < str.size(); i++)
    {
        std::string dest = m[str[i]].at(0).destAirportCode_destVertex;

        for (size_t j = 0; j < m[str[i]].size(); j++)
        {
            std::string dest = m[str[i]].at(j).destAirportCode_destVertex;
            REQUIRE(m[str[i]][j].lonAndLatPointsDest.first == m1[dest].first);
            REQUIRE(m[str[i]][j].lonAndLatPointsDest.second == m1[dest].second);
            REQUIRE(m[str[i]][j].distance_edgeWeight == graph.calculateDistance(m1[str[i]].first, m1[str[i]].second, m1[dest].first, m1[dest].second));
        }

        REQUIRE(m[str[i]].at(0).lonAndLatPointsDest.first == m1[dest].first);
        REQUIRE(m[str[i]].at(0).lonAndLatPointsDest.second == m1[dest].second);
        REQUIRE(m[str[i]].at(0).distance_edgeWeight == graph.calculateDistance(m1[str[i]].first, m1[str[i]].second, m1[dest].first, m1[dest].second));
    }
}

TEST_CASE("Graph codeToPosition contains longitudes and latitudes", "[weight=5][graph][7]")
{

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

TEST_CASE("Graph constructor populates adjacency_matrix_ properly", "[weight=5][graph][7]")
{
    REQUIRE(graph.getAdjacencyListEdge("AUH", "AMD").destAirportCode_destVertex == "AMD");
    REQUIRE(graph.getAdjacencyListEdge("AUH", "AMD").sourceAirportCode_sourceVertex == "AUH");
    REQUIRE(graph.getAdjacencyListEdge("AUH", "AMD").lonAndLatPointsSource.first == 24.433000564575195);
    REQUIRE(graph.getAdjacencyListEdge("AUH", "AMD").lonAndLatPointsSource.second == 54.651100158691406);
    REQUIRE(graph.getAdjacencyListEdge("AUH", "AMD").lonAndLatPointsDest.first == 23.0771999359);
    REQUIRE(graph.getAdjacencyListEdge("AUH", "AMD").lonAndLatPointsDest.second == 72.63469696039999);
    REQUIRE(graph.getAdjacencyListEdge("AUH", "AMD").distance_edgeWeight == graph.calculateDistance(23.0771999359, 72.63469696039999, 24.433000564575195, 54.651100158691406));
}

TEST_CASE("Graph constructor populates node_positions_ properly", "[weight=5][graph][7]")
{
    REQUIRE(graph.getNodePositions().at("THU").first == 76.5311965942);
    REQUIRE(graph.getNodePositions().at("SFJ").first == 67.0122218992);
    REQUIRE(graph.getNodePositions().at("GOH").first == 64.19090271);
    REQUIRE(graph.getNodePositions().at("UAK").first == 61.1604995728);
    REQUIRE(graph.getNodePositions().at("WWK").first == -3.58383011818);
    REQUIRE(graph.getNodePositions().at("POM").second == 147.22000122070312);
    REQUIRE(graph.getNodePositions().at("LAE").second == 146.725977);
    REQUIRE(graph.getNodePositions().at("HGU").second == 144.29600524902344);
    REQUIRE(graph.getNodePositions().at("GKA").second == 145.391998291);
}

TEST_CASE("Graph getAdjacencyListEdge gets the correct edges", "[weight=5][graph][7]")
{

    REQUIRE(graph.getAdjacencyListEdge("CAN", "AKL").destAirportCode_destVertex == "AKL");
    REQUIRE(graph.getAdjacencyListEdge("CAN", "AKL").lonAndLatPointsDest.first == -37.008098602299995);
    REQUIRE(graph.getAdjacencyListEdge("CAN", "AKL").lonAndLatPointsDest.second == 174.792007446);
    REQUIRE(graph.getAdjacencyListEdge("CAN", "AKL").lonAndLatPointsSource.first == 23.39240074157715);
    REQUIRE(graph.getAdjacencyListEdge("CAN", "AKL").lonAndLatPointsSource.second == 113.29900360107422);
    REQUIRE(graph.getAdjacencyListEdge("CAN", "AKL").sourceAirportCode_sourceVertex == "CAN");
    REQUIRE(graph.getAdjacencyListEdge("CAN", "AKL").distance_edgeWeight == graph.calculateDistance(23.39240074157715, 113.29900360107422, -37.008098602299995, 174.792007446));

    REQUIRE(graph.getAdjacencyListEdge("CAN", "MCT").destAirportCode_destVertex == "\\N");
    REQUIRE(graph.getAdjacencyListEdge("CAN", "MCT").lonAndLatPointsDest.first == (double)__INT_MAX__);
    REQUIRE(graph.getAdjacencyListEdge("CAN", "MCT").lonAndLatPointsDest.second == (double)__INT_MAX__);
    REQUIRE(graph.getAdjacencyListEdge("CAN", "MCT").lonAndLatPointsSource.first == (double)__INT_MAX__);
    REQUIRE(graph.getAdjacencyListEdge("CAN", "MCT").lonAndLatPointsSource.second == (double)__INT_MAX__);
    REQUIRE(graph.getAdjacencyListEdge("CAN", "MCT").sourceAirportCode_sourceVertex == "\\N");
    REQUIRE(graph.getAdjacencyListEdge("CAN", "MCT").distance_edgeWeight == (double)__INT_MAX__);
}
TEST_CASE("Graph getEdges gets the correct edges", "[weight=5][graph][9]")
{
    // TODO:
}

TEST_CASE("Graph populates airports_ properly", "[weight=5][graph][9]")
{
    // TODO:
}

TEST_CASE("Graph getAdjacentNodes works properly", "[weight=5][graph][9]")
{
    // TODO:
}

TEST_CASE("Graph populates airport_map_ properly", "[weight=5][graph][9]")
{
    // TODO:
}