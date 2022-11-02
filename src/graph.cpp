/**
 * @file graph.cpp
 * Final Project.
 */
#include "graph.h"

/**
This function will convert a csv to a vector of vector of strings. This will make it easier to work with the data.
*/
std::vector<std::vector<std::string>> Graph::csvToVect(std::string fileName)
{
    //@TODO:

    std::vector<std::vector<std::string>> v;

    std::string line;
    std::string word;

    std::ifstream file(fileName);

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