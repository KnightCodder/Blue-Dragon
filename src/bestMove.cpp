#include "analyzer.h"

Move ANALYZE::bestMove()
{
    totalMoves currentMoves = currentPosition.board.moveGeneration();

    double alpha = -std::numeric_limits<double>::infinity();
    double beta = std::numeric_limits<double>::infinity();
    int turn = currentPosition.board.turn;
    double best_score = -std::numeric_limits<double>::infinity();
    Move best_move;

    Position rollBack = currentPosition;

    for (int types = 0; types < MOVE::numOfPossibleTypesMoves; types++)
    {
        for (auto move : currentMoves[types])
        {

            currentPosition = rollBack;
            Move currentMove(types, move, PIECE::QUEEN);
            currentPosition.board.playMove(currentMove);
            Evaluation score = negamax(maxDepth - 1, -beta, -alpha);
            std::cout << move.first.print() << "_" << move.second.print() << " : " << score.eval << std::endl;
            score.eval *= -1;

            if (score.eval > best_score)
            {
                best_score = score.eval;
                best_move = currentMove;
            }
            alpha = std::max(alpha, score.eval);
        }
    }

    return best_move;
}
