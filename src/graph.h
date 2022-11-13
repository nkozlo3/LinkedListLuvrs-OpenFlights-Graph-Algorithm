/**
 * @file graph.h
 * Final Project.
 */

#pragma once

#include "cs225/PNG.h"
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <math.h>

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
    struct airport
    {
        std::pair<double, double> lonAndLatPoints;
        std::string airportCode;
        double distance;
    };

    // gets a map of edges
    double getEdges(std::string airpCode1, std::string airpCode2);

    // returns a vector of structs of every airport's destinations, lats/longs, and distances
    std::map<std::string, std::vector<airport>> sourceToDestLongLat(std::string txtFileName);

    // helper functions:
    double sourceToDestLongLatHelper(double sourceAirpLat, double sourceAirpLon, double destAirpLat, double destAirLon);
    std::vector<std::vector<std::string>> csvToVect(std::string filename, std::vector<int> columns = {-1});
    std::map<std::string, std::pair<double, double>> codeToPosition(std::string txtFileName);
    double numberNormalized(double originalMinRange, double originalMaxRange, double minRange, double maxRange, double position);
};