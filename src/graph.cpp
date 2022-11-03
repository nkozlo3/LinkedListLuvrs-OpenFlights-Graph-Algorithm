/**
 * @file graph.cpp
 * Final Project.
 */
#include "graph.h"

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

/**
 * @brief This function will convert our Codes.txt file to a map of codes to names of destinations.
 * @param txtFileName The name of the txt file (in our case, Codes.txt)
 * @return map of codes to names
 */
std::map<std::string, std::string> Graph::codeToName(std::string txtFileName)
{
    std::map<std::string, std::string> m;
    std::ifstream file(txtFileName);

    std::string word;
    std::stringstream ss;

    /**
     * loop through the file everytime we see a '(' we will have reached an airport code
     * when we see a ')' we will have reached the end of the airport code
     * everything from ',' to '(' will be the airport name
     * loop through the file each word is the space between the commas
     */
    std::string country = "";
    while (getline(file, word, ','))
    {
        std::string airportName = "";
        std::string airportCode = "";

        // if a country should be attached, attach it
        if (country != "")
        {
            airportName += country + ",";
            country = "";
        }

        // if there is a '(' in the word then this is a valid word to add to the map (it has an airport code and destination name)
        if (word.find("(") != std::string::npos)
        {
            // loop through the word until we see a ( and add each character before the ( to the airport name
            for (size_t i = 0; i < word.length(); i++)
            {
                if (word[i] == '(')
                {
                    // add the characters between ( and ) to the airport code
                    for (size_t j = i + 1; j < word.length(); j++)
                    {
                        if (word[j] == ')')
                        {
                            break;
                        }
                        airportCode += word[j];
                    }
                    break;
                }
                airportName += word[i];
            }

            // trim extra whitespaces
            if (std::isspace(*airportName.begin()))
                airportName.erase(airportName.begin());

            auto end = airportName.end();
            if (std::isspace(*(end - 1)))
                airportName.erase(end - 1);

            // add the airport code and name to the map
            m[airportCode] = airportName;
        }
        else
        {
            for (size_t i = 0; i < word.length(); i++)
            {
                country += word[i];
            }
        }
    }
    return m;
}

/**
 * This function will take an image of heght height and width width
 * Then map the correct pixelized location for our vectors of longitutes and latitudes
 * @brief Maps and normalizes longitudes and latitudes to pixels on a map
 * @param longitudes A vector of longitudes
 * @param latitudes A vector of latitudes
 * @param height The height of the image
 * @param width The width of the image
 * @return A 2D vector of x and y locations
 */
std::vector<std::vector<int>> Graph::imgLocationsMapping(std::vector<int> latitudes, std::vector<int> longitudes, int width, int height)
{

    // Right to left or width longitudes should run from -180 in the west to 180 in the east // with 0 at the exact center
    // Bottom to top or height latitudes should run from -90 in the south to 90 in the north // with 0 at the exact center

    std::vector<std::vector<int>> l;

    return l;
}
