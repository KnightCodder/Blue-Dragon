#include "dataGenerator.h"

void compilingPieceVision();

int main()
{
    compilingPieceVision();

    dataGenerator a(DATA_FILE::defaultInputFileName, DATA_FILE::defaultOutputFileName, DATA_FILE::defaultCacheFileName, DATA_FILE::latestRow);

    // a.setStartingRowNum(2); // to read the first game

    a.generateData(a.startingRowNum, 100);

    return 0;
}