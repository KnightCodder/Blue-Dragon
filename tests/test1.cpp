#include "analyzer.h"

void compilingPieceVision();

int main()
{
    compilingPieceVision();

    std::string startingFen = "r4Nk1/2q3p1/2p2r1p/2bp4/1p2Q1R1/1P5P/P5P1/4R2K w - - 2 36";

    ANALYZE a(startingFen, 6);

    Move bestMove = a.bestMove();

    bestMove.print();

    return 0;
}