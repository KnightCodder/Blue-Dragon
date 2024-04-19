#include "analyzer.h"

void compilingPieceVision();

int main()
{
    compilingPieceVision();

    std::string fen = "5rk1/5Npp/8/8/8/1Q6/8/6K1 w - - 0 1";

    ANALYZE a(fen, 4);

    Move bestmove = a.bestMove();

    bestmove.print();

    return 0;
}