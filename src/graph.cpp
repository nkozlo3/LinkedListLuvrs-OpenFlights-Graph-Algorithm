/**
 * @file graph.cpp
 * Final Project.
 */
#include "graph.h"

using namespace cs225;

Graph::Graph(bool weighted, int picNum, std::string picName)
{
    weighted_ = weighted;
    directed_ = true;
    picNum_ = picNum;
    picName_ = picName;

    // populate adjacency_list_
    adjacency_matrix_ = populateAdjacencyList("routes.csv");
}

Graph::Graph(bool weighted, bool directed, int picNum, std::string picName)
{
    weighted_ = weighted;
    directed_ = directed;
    picNum_ = picNum;
    picName_ = picName;

    // populate adjacency_list_
    adjacency_matrix_ = populateAdjacencyList("routes.csv");
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

bool Graph::vertexExists(Vertex v) const
{
    return assertVertexExists(v, "");
}

void Graph::insertVertex(Vertex v)
{
    // will overwrite if old stuff was there
   // removeVertex(v);
    // make it empty again
    adjacency_list[v] = unordered_map<Vertex, Edge>();
}

std::vector<Vertex> Graph::getAdjacent(Vertex source) const {
    auto lookup = adjacency_matrix_.find(source);

    if(lookup == adjacency_matrix_.end())
        return vector<Vertex>();

    else
    {
        std::vector<Vertex> vertex_list;
        std::unordered_map <Vertex, Edge> & map = adjacency_matrix_[source];
        for (auto it = map.begin(); it != map.end(); it++)
        {
            vertex_list.push_back(it->first);
        }
        return vertex_list;
    }
}

std::unordered_map<std::string, Graph::edge> Graph::getAdjacencyListUnorderedMap(std::string sourceCode)
{
    return adjacency_matrix_[sourceCode];
}

Graph::edge Graph::getAdjacencyListEdge(std::string sourceCode, std::string destCode)
{
    return adjacency_matrix_[sourceCode][destCode];
}

std::vector<std::string> Graph::getVertices()
{
    std::vector<std::string> vertices;

    for (auto it = adjacency_matrix_.begin(); it != adjacency_matrix_.end(); it++)
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

int Graph::getPicNum()
{
    return picNum_;
}

std::string Graph::getPicName()
{
    return picName_;
}

/**
 * Prints the graph to stdout
 */
void Graph::print()
{
    // for (auto it = adjacency_matrix_.begin(); it != adjacency_matrix_.end(); ++it)
    // {
    //     std::cout << it->first << std::endl;

    //     for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
    //     {
    //         std::stringstream ss;
    //         ss << it2->first;
    //         std::string vertexColumn = "    => " + ss.str();
    //         vertexColumn += " ";
    //         std::cout << std::left << std::setw(26) << vertexColumn;
    //         string edgeColumn = "edge label = \"" + it2->second.getLabel() + "\"";
    //         std::cout << std::left << std::setw(26) << edgeColumn;
    //         if (weighted)
    //             std::cout << "weight = " << it2->second.getWeight();
    //         std::cout << std::endl;
    //     }
    // }
}

void Graph::saveGraphAsPNG(std::string title)
{
    std::ofstream neatoFile;
    std::string filename = title + ".dot";
    neatoFile.open(filename.c_str());

    if (!neatoFile.good())
        std::cerr << "\033[1;31m[Graph Error]\033[0m "
                  << "couldn't create" << filename << std::endl;

    neatoFile
        << "strict graph G {\n"
        << "\toverlap=\"false\";\n"
        << "\tdpi=\"1300\";\n"
        << "\tsep=\"1.5\";\n"
        << "\tnode [fixedsize=\"true\", shape=\"circle\", fontsize=\"7.0\"];\n"
        << "\tedge [penwidth=\"1.5\", fontsize=\"7.0\"];\n";

    std::vector<std::string> vertices = getVertices();

    int xpos1 = 100;
    int xpos2 = 100;
    int xpos, ypos;

    for (auto it : vertices)
    {
        std::string current = it;
        neatoFile
            << "\t\""
            << current
            << "\"";
        if (current[1] == '1')
        {
            ypos = 100;
            xpos = xpos1;
            xpos1 += 100;
        }
        else
        {
            ypos = 200;
            xpos = xpos2;
            xpos2 += 100;
        }
        neatoFile << "[pos=\"" << xpos << "," << ypos << "\"]";
        neatoFile << ";\n";
    }

    neatoFile << "\tedge [penwidth=\"1.5\", fontsize=\"7.0\"];\n";

    size_t s = adjacency_matrix_.size();
    int amnt = 2;

    auto it1 = std::next(adjacency_matrix_.begin(), amnt);

    for (auto it = adjacency_matrix_.begin(); it != it1; ++it)
    {
        size_t s1 = it->second.size();
        int amnt1 = 1;

        auto it21 = std::next(it->second.begin(), amnt1);

        for (auto it2 = it->second.begin(); it2 != it21; ++it2)
        {
            std::string vertex1Text = it->first;
            std::string vertex2Text = it2->first;

            neatoFile << "\t\"";
            neatoFile << vertex1Text;
            neatoFile << "\" -- \"";
            neatoFile << vertex2Text;
            neatoFile << "\"";

            neatoFile << "[color=\"green\"]";

            if (weighted_)
                neatoFile << "[label=\"" << it2->second.distance_edgeWeight << "\"]";

            neatoFile << "[constraint = \"false\"]"
                      << ";\n";
        }
    }

    neatoFile << "}";
    neatoFile.close();
    std::string command = "neato -n -Tpng " + filename + " -o " + title + ".png 2> /dev/null";
    int result = system(command.c_str());

    if (result == 0)
    {
        std::cout << "Output graph saved as " << title << ".png" << std::endl;
    }
    else
    {
        std::cout << "Failed to generate visual output graph using `neato`" << std::endl;
    }
}

bool Graph::assertEdgeExists(Vertex source, Vertex destination, string functionName) const
{
    if(assertVertexExists(source,functionName) == false)
        return false;
    if(adjacency_matrix_[source].find(destination)== adjacency_matrix_[source].end())
    {
        if (functionName != "")
            error(functionName + " called on nonexistent edge " + source + " -> " + destination);
        return false;
    }

    if(!directed)
    {
        if (assertVertexExists(destination,functionName) == false)
            return false;
        if(adjacency_matrix_[destination].find(source)== adjacency_matrix_[destination].end())
        {
            if (functionName != "")
                error(functionName + " called on nonexistent edge " + destination + " -> " + source);
            return false;
        }
    }
    return true;
}

bool Graph::assertVertexExists(Vertex v, string functionName) const
{
    if (adjacency_matrix_.find(v) == adjacency_matrix_.end())
    {
        if (functionName != "")
            error(functionName + " called on nonexistent vertices");
        return false;
    }
    return true;
}