#include "analyzer.h"

const double negInf = -std::numeric_limits<double>::infinity();
const double posInf = std::numeric_limits<double>::infinity();

Evaluation evaluate(Board b)
{
    double e = b.turn * 1.0 * b.materialBalance;

    return Evaluation(GameStatus::STILL_GOING, e);
}

Evaluation ANALYZE::negamax(int depth, double alpha, double beta)
{
    searchTree.push(currentPosition);
    // std::cout << "1 : " << depth << std::endl;

    totalMoves currentMoves = currentPosition.board.moveGeneration();

    if (currentPosition.board.checks)
        depth++;

    if (currentPosition.board.illegal)
        return Evaluation(GameStatus::ILLEGAL);

    if (currentPosition.board.fiftyMoves >= 100)
        return Evaluation(GameStatus::DRAW);

    auto it = ThreeFoldRepetition.find(currentPosition);
    if (it != ThreeFoldRepetition.end() && it->second >= 3)
        return Evaluation(GameStatus::DRAW);

    if (depth == 0)
    {
        // std::cout << "2 : " << depth << std::endl;
        return evaluate(currentPosition.board);
    }

    double max_score = negInf;

    bool mate = true;

    for (int types = 0; types < MOVE::numOfPossibleTypesMoves; types++)
    {
        for (auto move : currentMoves[types])
        {
            // std::cout << "3 : " << depth << std::endl;
            currentPosition.board.playMove(Move(types, move, PIECE::QUEEN));
            ThreeFoldRepetition[currentPosition]++;

            Evaluation score;
            if (types == MOVE::capturesIndex || types == MOVE::checksIndex)
            {
                score = negamax(depth - 1, -beta, -alpha);
            }
            else
            score = negamax(depth - 1, -beta, -alpha);
            // std::cout << "4 : " << depth << std::endl;

            auto it = ThreeFoldRepetition.find(currentPosition);
            if (it != ThreeFoldRepetition.end() && it->second > 0)
                it->second--;

            searchTree.pop();
            score.eval *= -1;

            // std::cout << "5 : " << depth << " | search tree size : " << searchTree.size() << std::endl;
            currentPosition = searchTree.top();

            if (score.status != GameStatus::ILLEGAL)
            {
                // std::cout << "6 : " << depth << std::endl;
                mate = false;
                max_score = std::max(max_score, score.eval);
                alpha = std::max(alpha, score.eval);
                if (alpha >= beta)
                {
                    break;
                }
            }
        }
    }

    if (mate)
    {
        if (currentPosition.board.checks)
            return (currentPosition.board.turn == TURN::white) ? Evaluation(GameStatus::BLACK_WINS, posInf) : Evaluation(GameStatus::WHITE_WINS, negInf);
            // return (currentPosition.board.turn == TURN::white) ? Evaluation(GameStatus::BLACK_WINS, negInf) : Evaluation(GameStatus::WHITE_WINS, posInf);

        return Evaluation(GameStatus::DRAW);
    }

    return Evaluation(GameStatus::STILL_GOING, max_score);
}
