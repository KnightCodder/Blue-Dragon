#ifndef GENERATEDATA_h
#define GENERATEDATA_h

#include "game.h"
#include <fstream>

class dataGenerator
{
    std::string inputFileName;
    std::string outputFileName;
    std::string cacheFileName;
    // std::string tempFileName = "data/tempTrainingData.csv";
    bool reading = false;
    bool writing = false;


public:
    int startingRowNum;

    dataGenerator(std::string inputfilename, std::string outputfilename, std::string cachefilename, int startingrownum = DATA_FILE::latestRow)
    {
        inputFileName = inputfilename;
        outputFileName = outputfilename;
        cacheFileName = cachefilename;

        if (startingrownum == DATA_FILE::latestRow)
            startingRowNum = getStartingRowNum();
        else 
            startingRowNum = startingrownum;

        std::cout << "Data Generator would take input from : " << inputFileName << std::endl;
        std::cout << "Data Generator would give output on : " << outputFileName << std::endl;
        std::cout << "cache file name is : " << cacheFileName << std::endl;
        std::cout << "Current input file pointer is on line " << startingRowNum << std::endl;
    }

    int getStartingRowNum();

    void setStartingRowNum(int newRow);

    void generateData(int startingrownum, int numOfRows = 1);
};

#endif