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
std::vector<std::vector<std::string>> Graph::csvToVect(std::string fileName)
{
    //TODO:

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
    while (getline(file, line))
    {
        std::vector<std::string> w;

        std::stringstream ss(line);
        while (getline(ss, word, ','))
        {
            w.push_back(word);
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
    //TODO:

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
    while (getline(file, word, ','))
    {
        std::string airportName = "";
        std::string airportCode = "";

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
            // add the airport code and name to the map
            m[airportCode] = airportName;
        }
    }
    return m;
}