#include "analyzer.h"

void compilingPieceVision();

int main()
{
    compilingPieceVision();

    std::string startingFen = "3rr1k1/5ppp/8/8/8/8/4RPPP/4R1K1 w - - 0 1";

    ANALYZE a(startingFen, 6);

    Move bestMove = a.bestMove();

    bestMove.print();

    return 0;
}