#include "dataGenerator.h"

void compilingPieceVision();

int main()
{
    compilingPieceVision();

    // dataGenerator a(DATA_FILE::defaultInputFileName, DATA_FILE::defaultOutputFileName, DATA_FILE::defaultCacheFileName, DATA_FILE::latestRow);

    // // a.setStartingRowNum(2); // to read the first game

    // a.generateData(a.startingRowNum, 200);

    Position b(Board("rnbqkbnr/1ppppp2/p5pp/8/3PP3/2N2N2/PPP2PPP/R1BQKB1R b KQkq - 1 4"), 4, 1, {{1, 1}, {1, 1}});

    std::ofstream file("data/temp.csv", std::ios::app);

    if (!file.is_open())
    {
        std::cerr << "Error opening file for appending : " << "data/temp.csv" << std::endl;
    }

    file << b.toCSV();

    return 0;
}