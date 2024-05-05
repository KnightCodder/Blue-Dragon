#include "analyzer.h"
#include "dataGenerator.h"

void compilingPieceVision();

int main()
{
    compilingPieceVision();

    // dataGenerator a(DATA_FILE::defaultInputFileName, DATA_FILE::defaultOutputFileName, DATA_FILE::defaultCacheFileName);
    // a.generateData(a.startingRowNum, 1000);


    ANALYZE a("2r2rk1/p2q1pp1/4p2p/3p1b2/1p1P3P/5N2/QP3PP1/3N2KR w - - 0 21", 2);

    Move f = a.bestMove();

    f.print();

    return 0;
}
