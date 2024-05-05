#include "analyzer.h"

void compilingPieceVision();

int main()
{
    compilingPieceVision();

    std::string startingFen = "rnbqkbnr/ppp1pppp/8/3p4/3P4/8/PPP1PPPP/RNBQKBNR w KQkq - 0 2";

    // a.searchTree.push(a.currentPosition);
    // a.negamax(a.maxDepth, -10, 5);

    ANALYZE a(startingFen, 2);
    Move bestMove = a.bestMove();
    bestMove.print();

    // Evaluator f;

    // double evaluation = f.evaluate(Position(Board(startingFen), 2));

    // std::cout << "eval : " << evaluation << std::endl;
    // f.printModel();

    return 0;
}
