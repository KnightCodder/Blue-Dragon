#include "dataGenerator.h"

void dataGenerator::setStartingRowNum(int newRow){
    std::ofstream outputFile(cacheFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open cache file for writing: " << cacheFileName << std::endl;
        return;
    }

    outputFile << newRow;
    startingRowNum = newRow;
    outputFile.close();
}