#include "dataGenerator.h"

int dataGenerator::getStartingRowNum()
{
    std::ifstream file(cacheFileName);
    int rowNum;

    if (file.is_open())
    {
        std::string line;
        std::getline(file, line); // Read the first line
        std::istringstream iss(line);
        iss >> rowNum;

        file.close();
    }
    else
    {
        std::cerr << "Unable to open cache file: " << cacheFileName << std::endl;
    }

    return rowNum;
}