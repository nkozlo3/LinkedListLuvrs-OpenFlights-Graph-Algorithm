/**
 * @file graph.h
 * Final Project.
 */

#pragma once

#include "cs225/PNG.h"
#include <vector>
#include <unordered_map>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <ostream>
#include <map>
#include <string>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <numbers>

using namespace cs225;

/**
 * airports.csv is formatted as:
 * "Airline ID", "Name of the airline", "Alias of the airline", "2-letter IATA code", "3 letter ICAO code", "Callsign", "Country", "Active or not"
 *
 * NULL values are represented with \N
 */

/**
 * routes.csv is formatted as follows:
 * "Airline IATA/ICAO", "Airline ID", "Source airport", "Source airport ID", "Destination airport IATA/ICAO", "Codeshare", "Stops", "Equipment"
 *
 *
 * Airline	2-letter (IATA) or 3-letter (ICAO) code of the airline.
 * Airline ID	Unique OpenFlights identifier for airline (see Airline).
 * Source airport	3-letter (IATA) or 4-letter (ICAO) code of the source airport.
 * Source airport ID	Unique OpenFlights identifier for source airport (see Airport)
 * Destination airport	3-letter (IATA) or 4-letter (ICAO) code of the destination airport.
 * Destination airport ID	Unique OpenFlights identifier for destination airport (see Airport)
 * Codeshare	"Y" if this flight is a codeshare (that is, not operated by Airline, but another carrier), empty otherwise.
 * Stops	Number of stops on this flight ("0" for direct)
 * Equipment	3-letter codes for plane type(s) generally used on this flight, separated by spaces
 */

class Graph
{

public:
    struct pairOfAirports
    {
        std::pair<double, double> lonAndLatPointsSource;
        std::pair<double, double> lonAndLatPointsDest;
        std::string sourceAirportCode_sourceVertex;
        std::string destAirportCode_destVertex;
        double distance_edgeWeight;

        bool operator<(const pairOfAirports &other) const
        {
            return distance_edgeWeight < other.distance_edgeWeight;
        }
    };
    struct airport
    {
        std::pair<double, double> lonAndLatPoints;
        std::string airportCode;
        int index;    // this index will be useful in our stronglyConnected class
        int lowLink;  // this will also be useful for our stronglyConnected class
        bool onStack; // this will be used to check if we are on the stack in stronglyconnected class

        bool operator==(const airport &other) const
        {
            return airportCode == other.airportCode;
        }
        bool operator!=(const airport &other) const
        {
            return airportCode != other.airportCode;
        }
    };

    Graph();
    // constructors
    /**
     * Constructor to create an empty graph.
     * populates @private @var adjacency_list
     * @param weighted - specifies whether the graph is a weighted graph or
     *  not
     */
    Graph(bool weighted, int picNum, std::string picName, std::string imageName);

    /**
     * Constructor to create an empty graph.
     * populates @private @var adjacency_list
     * @param weighted - specifies whether the graph is a weighted graph or
     *  not
     * @param directed - specifies whether the graph is directed
     */
    Graph(bool weighted, bool directed, int picNum, std::string picName, std::string imageName);

    /**
     * @cite inspired by cs225's, lab_ml, graph class, getVetices function
     * Gets all vertices in the graph.
     * @return a vector of all vertices in the graph
     */
    ////returns a vector of strings of airport codes
    std::vector<std::string> getVertices();

    /**
     * Saves the graph on a PNG image.
     * @param title - the filename of the PNG image
     */
    void drawGraphOnPNG(std::pair<double, double> h1h2, std::pair<double, double> s1s2,
                        std::pair<double, double> l1l2, int xNodeSize, int yNodeSize, std::string newFileName, bool nodes, bool vertices);

    std::vector<std::pair<double, double>> drawNodesOfGraphOnPNG(double h, double s, double l, int xSize, int ySize);
    void drawEdgesOfGraphOnPNG(double h, double s, double l);

    // Populate adjacency_list
    std::unordered_map<std::string, std::unordered_map<std::string, Graph::pairOfAirports>> populateAdjacencyList(std::string textFileName);

    // helper functions:

    /**
     * This function returns a vector of every edge
     * @return a vector of edges
     */
    std::vector<Graph::pairOfAirports> getEdges();

    /**
     * @return the coresponding map of adjacancyMatrix[sourceCode]
     */
    std::unordered_map<std::string, Graph::pairOfAirports> getAdjacentMap(std::string sourceCode);

    /**
     * This function returns a map of edges
     * @param txtFileName - the name of the text file to be read
     * @return a map of edges
     */
    std::map<std::string, std::vector<pairOfAirports>> sourceToDestLongLat(std::string txtFileName);

    /**
     * This function returns the distance between two points
     * @param lon1 - the longitude of the first point
     * @param lat1 - the latitude of the first point
     * @param lon2 - the longitude of the second point
     * @param lat2 - the latitude of the second point
     * @return the distance between the two points
     */
    double calculateDistance(double sourceAirpLat, double sourceAirpLon, double destAirpLat, double destAirLon);

    /**
     * This function converts a csv file to a vector of vectors
     * @param txtFileName - the name of the text file to be read
     * @param columns - the columns of the text file to be read
     * @return a vector of vectors
     */
    std::vector<std::vector<std::string>> csvToVect(std::string filename, std::vector<int> columns = {-1});

    /**
     *
     * LATITUDE IS MAPPED TO FIRST LONGITITUDE TO SECOND
     *
     * This function returns a map where the key is the airport code and the value is the longitude and latitude of the airport in a pair
     * @param txtFileName - the name of the text file to be read
     * @return a map where the key is the airport code and the value is the longitude and latitude of the airport in a pair
     */
    std::map<std::string, std::pair<double, double>> codeToPosition(std::string txtFileName);

    /**
     * This function normalizes a number between minRange and maxRange
     * @param originalMinRange - the original minimum range
     * @param originalMaxRange - the original maximum range
     * @param minRange - the minimum range
     * @param maxRange - the maximum range
     * @param position - the position to be normalized
     * @return the normalized position
     */
    double numberNormalized(double originalMinRange, double originalMaxRange, double minRange, double maxRange, double position);

    /**
     *
     */
    std::pair<double, double> latitudeToXAndYPos(double longitude, double latitude, double width, double height);

    Graph::pairOfAirports getAdjacencyListEdge(std::string sourceCode, std::string destCode);

    std::vector<std::string> getAdjacentNodes(std::string airpCode);

    std::map<std::string, std::pair<double, double>> populatePixelPoints();

    std::vector<Graph::airport> populateAirports();

    std::vector<Graph::airport> getAirports();

    std::map<std::string, airport> getAirportsMap();

    int getPicNum();

    std::string getPicName();

    double degToRadian(double degrees);

    PNG getPng();
    // maps a source airport to a map of all it's destination airports.
    // second map is the adjacency list of the first (adj nodes)
    std::unordered_map<std::string, std::unordered_map<std::string, pairOfAirports>> getAdjacanceMatrix();
    std::map<std::string, std::pair<double, double>> getNodePositions();
    std::map<std::string, std::pair<double, double>> getPixelPoints();

private:
    // map from airport to a map of destinations from that airport
    mutable std::unordered_map<std::string, std::unordered_map<std::string, pairOfAirports>> adjacency_matrix_;
    
    // map of node positions where [airportCode] maps to pair<lon, lat>
    mutable std::map<std::string, std::pair<double, double>> node_positions_;
    // lonLatcoordinates converted to xy points
    mutable std::map<std::string, std::pair<double, double>> pixel_points_;
    // a map from an airport code to it's airport struct
    mutable std::map<std::string, airport> airports_map_;

    // Nodes that exist on our map
    std::vector<std::pair<double, double>> existingNodes_;
    // a list of airport structs
    std::vector<airport> airports_;

    int picNum_;
    string picName_;
    bool weighted_;
    bool directed_;
    PNG png_;
};