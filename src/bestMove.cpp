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
    isGameOver = true;

    for (int types = 0; types < MOVE::numOfPossibleTypesMoves; types++)
    {
        for (auto move : currentMoves[types])
        {
            currentPosition = rollBack;
            Move currentMove(types, move, PIECE::QUEEN);
            currentPosition.board.playMove(currentMove);
            searchTree.push(currentPosition);
            Evaluation score = negamax(maxDepth - 1, -beta, -alpha);
            searchTree.pop();
            score.eval *= -1;

            if (score.status == GameStatus::ILLEGAL)
                continue;
            isGameOver = false;

            // std::cout << move.first.print() << "_" << move.second.print() << " : " << score.eval << std::endl;

            if (score.eval > best_score)
            {
                best_score = score.eval;
                best_move = currentMove;
            }
            alpha = std::max(alpha, score.eval);
        }
    }


    currentPosition = rollBack;

    return best_move;
}
