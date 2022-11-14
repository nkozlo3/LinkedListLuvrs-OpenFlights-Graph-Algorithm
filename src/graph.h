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
    struct edge
    {
        std::pair<double, double> lonAndLatPointsSource;
        std::pair<double, double> lonAndLatPointsDest;
        std::string sourceAirportCode_sourceVertex;
        std::string destAirportCode_destVertex;
        double distance_edgeWeight;

        bool operator<(const edge &other) const
        {
            return distance_edgeWeight < other.distance_edgeWeight;
        }
    };
    // constructors
    /**
     * Constructor to create an empty graph.
     * populates @private @var adjacency_list
     * @param weighted - specifies whether the graph is a weighted graph or
     *  not
     */
    Graph(bool weighted, int picNum, std::string picName);

    /**
     * Constructor to create an empty graph.
     * populates @private @var adjacency_list
     * @param weighted - specifies whether the graph is a weighted graph or
     *  not
     * @param directed - specifies whether the graph is directed
     */
    Graph(bool weighted, bool directed, int picNum, std::string picName);

    /**
     * @cite inspired by cs225's, lab_ml, graph class, getVetices function
     * Gets all vertices in the graph.
     * @return a vector of all vertices in the graph
     */
    std::vector<std::string> getVertices();

    /**
     * @cite inspired by cs225's, lab_ml, graph class, print function
     * Prints the graph to stdout
     */
    void print(); // TODO:

    /**
     * @cite inspired by cs225's, lab_ml, graph class, savePNG function
     * Saves the graph as a PNG image.
     * @param title - the filename of the PNG image
     */
    void saveGraphAsPNG(std::string title); // TODO:

    // Populate adjacency_list
    std::unordered_map<std::string, std::unordered_map<std::string, Graph::edge>> populateAdjacencyList(std::string textFileName);

    // helper functions:

    /**
     * This function returns a map of edges
     * @return a map of edges
     */
    double getEdges(std::string airpCode1, std::string airpCode2);

    /**
     * This function returns a map of edges
     * @param txtFileName - the name of the text file to be read
     * @return a map of edges
     */
    std::map<std::string, std::vector<edge>> sourceToDestLongLat(std::string txtFileName);

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

    std::unordered_map<std::string, Graph::edge> getAdjacencyListUnorderedMap(std::string sourceCode);

    Graph::edge getAdjacencyListEdge(std::string sourceCode, std::string destCode);

    int getPicNum();

    std::string getPicName();

private:
    // adjacency_list at [sourceCode][destCode] = edge
    mutable std::unordered_map<std::string, std::unordered_map<std::string, edge>> adjacency_matrix_;

    int picNum_;
    string picName_;
    bool weighted_;
    bool directed_;
};