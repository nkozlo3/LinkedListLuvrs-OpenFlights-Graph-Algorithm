/**
 * @file graph.cpp
 * Final Project.
 */
#include "graph.h"

using namespace cs225;

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
 * This function will take an image of heght height and width width
 * Then map the correct pixelized location for our vectors of longitutes and latitudes
 * @brief Maps and normalizes longitudes and latitudes to pixels on a map
 * @param longitudes A vector of longitudes
 * @param latitudes A vector of latitudes
 * @param height The height of the image
 * @param width The width of the image
 * @return A 2D vector of x and y locations
 */
std::vector<std::vector<string>> Graph::imgLocationsMapping(std::vector<std::vector<std::string>> latsAndLongs, int width, int height)
{
    // TODO:
    //  Right to left or width longitudes should run from -180 in the west to 180 in the east // with 0 at the exact center
    //  Bottom to top or height latitudes should run from -90 in the south to 90 in the north // with 0 at the exact center

    for (size_t i = 0; i < latsAndLongs.size(); i++)
    {
        latsAndLongs[i][7] = std::to_string((int)numberNormalized(-180, 180, 0, width, std::stod(latsAndLongs[i][7])));
        latsAndLongs[i][8] = std::to_string((int)numberNormalized(-90, 90, 0, width, std::stod(latsAndLongs[i][8])));
    }

    return latsAndLongs;
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
