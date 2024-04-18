#include "analyzer.h"

Evaluation evaluate(Board b)
{
    double e = b.turn * 1.0 * b.materialBalance;

    return Evaluation(GameStatus::STILL_GOING, e);
}

Evaluation ANALYZE::negamax(int depth, double alpha, double beta)
{
    totalMoves currentMoves = currentPosition.board.moveGeneration();

    if (currentPosition.board.illegal)
        return Evaluation(GameStatus::ILLEGAL);
    
    if (depth == 0)
        return evaluate(currentPosition.board);

    double max_score = -std::numeric_limits<double>::infinity();

    searchTree[maxDepth - depth] = currentPosition;

    for (int types = 0; types < MOVE::numOfPossibleTypesMoves; types++)
    {
        for (auto move : currentMoves[types])
        {
            currentPosition = searchTree[maxDepth - depth];
            currentPosition.board.playMove(Move(types, move, PIECE::QUEEN));
            Evaluation score = negamax(depth - 1, -beta, -alpha);
            score.eval *= -1;

            max_score = std::max(max_score,score.eval);
            alpha = std::max(alpha, score.eval);
            if (alpha >= beta)
            {
                break;
            }
        }
    }

    return Evaluation(GameStatus::STILL_GOING, max_score);
}
