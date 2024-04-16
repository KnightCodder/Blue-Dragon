#include "dataGenerator.h"

void compilingPieceVision();

int main()
{
    compilingPieceVision();

    dataGenerator a(DATA_FILE::defaultInputFileName, DATA_FILE::defaultOutputFileName, DATA_FILE::defaultCacheFileName, DATA_FILE::latestRow);

    a.setStartingRowNum(2);

    a.generateData(a.startingRowNum, 1);

    return 0;
}