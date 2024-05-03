#ifndef DEFINATION_H_INCLUDED
#define DEFINATION_H_INCLUDED

#include "basicDefination.h"

namespace DATA_FILE
{
    const std::string defaultInputFileName = "data/games.csv";
    const std::string defaultOutputFileName = "data/trainingData.csv";
    const std::string defaultCacheFileName = "cache/startingRowNum.txt";
    const int latestRow = -1;
    const int movesIndex = 26;
    const int resultIndex = 32;
}

namespace TRAINING_DATA
{
    const int moveNumIndex = 0;
    const int turnIndex = 1;
    const int checksIndex = 2;
    const int KcastleIndex = 3;
    const int QcastleIndex = 4;
    const int kcastleIndex = 5;
    const int qcastleIndex = 6;
    const int fiftyMovesIndex = 7;
    const int materialIndex = 8;
    const int evalIndex = 9;
    const int pawnIndex = 0;
    const int knightIndex = 1;
    const int bishopIndex = 2;
    const int rookIndex = 3;
    const int kingIndex = 4;
    const int colorIndex = 5;
    const int WwatchersIndex = 6;
    const int BwatchersIndex = 7;
    const int EwatchingIndex = 8;
    const int WwatchingIndex = 9;
    const int BwatchingIndex = 10;
    const int KwatchingIndex = 11;
}

#endif