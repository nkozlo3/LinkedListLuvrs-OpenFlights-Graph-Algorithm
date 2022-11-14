/**
 * @file graph.cpp
 * Final Project.
 */
#include "graph.h"

using namespace cs225;

Graph::Graph(bool weighted)
{
    weighted_ = weighted;
    directed_ = true;

    // populate adjacency_list
    adjacency_list = populateAdjacencyList("routes.csv");
}

Graph::Graph(bool weighted, bool directed)
{
    weighted_ = weighted;
    directed_ = directed;

    // populate adjacency_list
    adjacency_list = populateAdjacencyList("routes.csv");
}

std::unordered_map<std::string, std::unordered_map<std::string, Graph::edge>> Graph::populateAdjacencyList(std::string txtFileName)
{
    std::vector<std::vector<std::string>> v2 = csvToVect(txtFileName, {2, 4});
    std::map<std::string, std::pair<double, double>> points = codeToPosition("airports.csv");

    std::unordered_map<std::string, std::unordered_map<std::string, edge>> m2;

    std::string currSource = "";

    std::unordered_map<std::string, edge> currUnorderedMap;

    for (size_t i = 0; i < v2.size(); i++)
    {
        edge struc;
        if (!currUnorderedMap.empty())
            currUnorderedMap.clear();

        if (m2.find(v2[i][0]) == m2.end())
            currSource = v2[i][0];
        else
            continue;

        for (size_t i = 0; i < v2.size(); i++)
        {
            if (v2[i][0] == currSource)
            {
                struc.sourceAirportCode_sourceVertex = v2[i][0];
                struc.destAirportCode_destVertex = v2[i][1];

                struc.lonAndLatPointsSource.first = points[v2[i][0]].first;
                struc.lonAndLatPointsSource.second = points[v2[i][0]].second;
                struc.lonAndLatPointsDest.first = points[v2[i][1]].first;
                struc.lonAndLatPointsDest.second = points[v2[i][1]].second;

                struc.distance_edgeWeight = calculateDistance(points[v2[i][0]].first, points[v2[i][0]].second, points[v2[i][1]].first, points[v2[i][1]].second);
                currUnorderedMap[v2[i][1]] = struc;
            }
        }

        m2[currSource] = currUnorderedMap;
    }
    return m2;
}

std::unordered_map<std::string, Graph::edge> Graph::getAdjacencyListUnorderedMap(std::string sourceCode)
{
    return adjacency_list[sourceCode];
}

Graph::edge Graph::getAdjacencyListEdge(std::string sourceCode, std::string destCode)
{
    return adjacency_list[sourceCode][destCode];
}

std::vector<std::string> Graph::getVertices()
{
    std::vector<std::string> vertices;

    for (auto it = adjacency_list.begin(); it != adjacency_list.end(); it++)
    {
        vertices.push_back(it->first);
    }
    return vertices;
}

double Graph::getEdges(std::string sourceAirpCode, std::string destAirpCode)
{
    std::map<std::pair<std::string, std::string>, double> m;
    std::map<std::string, std::vector<Graph::edge>> pairs = sourceToDestLongLat("routes.csv");
    double distance = sqrt(std::pow(pairs[sourceAirpCode][0].lonAndLatPointsSource.first - pairs[destAirpCode][0].lonAndLatPointsSource.first, 2) + std::pow(pairs[sourceAirpCode][0].lonAndLatPointsSource.second - pairs[destAirpCode][0].lonAndLatPointsSource.second, 2));
    return distance;
}

double Graph::calculateDistance(double sourceAirpLat, double sourceAirpLon, double destAirpLat, double destAirLon)
{
    double distance = sqrt(std::pow(sourceAirpLat - destAirpLat, 2) + std::pow(sourceAirpLon - destAirLon, 2));
    return distance;
}

/**
 * @brief Converts a csv file to a vector of vectors of strings
 * @param filename The name of the csv file
 * @return A vector of vectors of strings
 */
std::vector<std::vector<std::string>> Graph::csvToVect(std::string fileName, std::vector<int> columns)
{
    std::vector<std::vector<std::string>> v;

    std::string line;
    std::string word;

    std::ifstream file(fileName);

    /**
     * Loop through every line in the csv file.
     * Then loop through every word in that line of the csv file.
     * Add every word in an individual line ot a new vector of strings
     * Add the full vector of strings of the line to the vector of vectors of strings
     */
    while (std::getline(file, line))
    {
        std::vector<std::string> w;

        std::stringstream ss(line);

        int column = 0;

        size_t placeInVect = 0;

        while (std::getline(ss, word, ','))
        {
            if (columns[0] == -1)
                w.push_back(word);
            else
            {
                if (placeInVect < columns.size() && columns[placeInVect] == column)
                {
                    w.push_back(word);
                    placeInVect++;
                }
                column++;
            }
        }
        v.push_back(w);
    }
    return v;
}

std::map<std::string, std::pair<double, double>> Graph::codeToPosition(std::string txtFileName)
{
    std::map<std::string, std::pair<double, double>> m;
    /**
     * loop through the airports.csv file and add the IATA code and the latitude and longitude to a map
     * The IATA is on the fourth column and the latitude and longitude are on the 6th and 7th column
     * The IATA is the key and the vector of latitude and longitude are the value
     * We can use csvToVect to get all the values into a vector of vectors of strings
     * if IATA is null it will have the \N in which case we will use the ICAO code instead
     * IACO is on the 5th column
     */
    std::vector<std::vector<std::string>> v = csvToVect(txtFileName);
    std::pair<double, double> w;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i][4] != "\\N")
        {
            double lat = std::strtod(v[i][6].c_str(), nullptr);
            double lon = std::strtod(v[i][7].c_str(), nullptr);
            w.first = lat;
            w.second = lon;
            v[i][4].erase(0, 1);
            v[i][4].erase(v[i][4].end() - 1);
            m[v[i][4]] = w;
        }
        // else don't add it to the map
    }
    return m;
}

/**
 * @brief This function will map our IACO and ICAO codes to a vector of distances
 * @param txtFileName The name of the txt file (in our case, Codes.txt)
 * @return map of edges
 */
std::map<std::string, std::vector<Graph::edge>> Graph::sourceToDestLongLat(std::string txtFileName)
{
    // Now we need to compile a map of every destination that each individual airport has
    // we have a routes file that has the source and destination IATA codes
    // the source is on the 3rd column and the destination is on the 5th column
    // The key is the source and the value is a vector of destinations

    std::vector<std::vector<std::string>> v2 = csvToVect(txtFileName, {2, 4});
    std::map<std::string, std::pair<double, double>> points = codeToPosition("airports.csv");

    std::map<std::string, std::vector<edge>> m2;

    std::string currSource = "";

    std::vector<edge> currVect;

    for (size_t i = 0; i < v2.size(); i++)
    {
        edge struc;
        if (!currVect.empty())
            currVect.clear();

        if (m2.find(v2[i][0]) == m2.end())
            currSource = v2[i][0];
        else
            continue;

        for (size_t i = 0; i < v2.size(); i++)
        {
            if (v2[i][0] == currSource)
            {
                struc.sourceAirportCode_sourceVertex = v2[i][0];
                struc.destAirportCode_destVertex = v2[i][1];

                struc.lonAndLatPointsSource.first = points[v2[i][0]].first;
                struc.lonAndLatPointsSource.second = points[v2[i][0]].second;
                struc.lonAndLatPointsDest.first = points[v2[i][1]].first;
                struc.lonAndLatPointsDest.second = points[v2[i][1]].second;

                struc.distance_edgeWeight = calculateDistance(points[v2[i][0]].first, points[v2[i][0]].second, points[v2[i][1]].first, points[v2[i][1]].second);
                currVect.push_back(struc);
            }
        }

        m2[currSource] = currVect;
    }
    return m2;
}

/**
 * @brief This function normalizes the number position between originalMinRange and originalMaxRange given an origonal position between minRange and maxRange
 * @param originalMinRange The original minimum range
 * @param originalMaxRange The original maximum range
 * @param minRange The new minRange
 * @param maxRange The new maxRange
 * @param position The number we are normalizing
 * @return the normalized number
 */
double Graph::numberNormalized(double originalMinRange, double originalMaxRange, double minRange, double maxRange, double position)
{
    double invLerp = (position - originalMinRange) / (originalMaxRange - originalMinRange);

    return (1 - invLerp) * minRange + maxRange * invLerp;
}