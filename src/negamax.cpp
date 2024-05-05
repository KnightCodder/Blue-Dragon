#include "analyzer.h"

const double negInf = -std::numeric_limits<double>::infinity();
const double posInf = std::numeric_limits<double>::infinity();

Evaluator evaluator;

Evaluation evaluate(Position b)
{
    double e =  evaluator.evaluate(b);

    return Evaluation(GameStatus::STILL_GOING, e);
}

Evaluation ANALYZE::negamax(int depth, double alpha, double beta)
{
    // if (searchTree.size() == 1)
    // {
    //     std::cout << "wtf" << std::endl;
    // }

    totalMoves currentMoves = currentPosition.board.moveGeneration();

    // printf("1");

    if (currentPosition.board.illegal)
    {
    // printf("6");
        return Evaluation(GameStatus::ILLEGAL);
    }

    if (currentPosition.board.fiftyMoves >= 100)
    {

    // printf("7");
        return Evaluation(GameStatus::DRAW);
    }

    auto it = ThreeFoldRepetition.find(currentPosition);
    // printf("8");
    if (it != ThreeFoldRepetition.end() && it->second >= 3)
    {
        std::cout << "three fold" << std::endl;
        return Evaluation(GameStatus::DRAW);
    }

    if (depth == 0)
    {
    // printf("9");
        return evaluate(currentPosition);
    }
    // printf("2");

    double max_score = negInf;

    bool mate = true;
    bool pron = false;

    for (int types = 0; types < MOVE::numOfPossibleTypesMoves; types++)
    {
        for (auto move : currentMoves[types])
        {
            currentPosition.board.playMove(Move(types, move, PIECE::QUEEN));
            searchTree.push(currentPosition);
            ThreeFoldRepetition[currentPosition]++;

            Evaluation score;

            // if (types == MOVE::capturesIndex || types == MOVE::checksIndex)
            // {
            //     score = negamax(depth, -beta, -alpha);
            // }
            // else
            score = negamax(depth - 1, -beta, -alpha);

            auto it = ThreeFoldRepetition.find(currentPosition);
            if (it != ThreeFoldRepetition.end() && it->second > 0)
            {
                std::cout << "doing something with 3 fold" << std::endl;
                it->second--;
            }

            searchTree.pop();
            score.eval *= -1;

            currentPosition = searchTree.top();

            if (score.status != GameStatus::ILLEGAL)
            {
                mate = false;
                max_score = std::max(max_score, score.eval);
                alpha = std::max(alpha, score.eval);
                // if (alpha >= beta)
                // {
                //     pron = true;
                //     break;
                // }
            }
        }
        if (pron)
            break;
    }

    // printf("3");
    if (mate)
    {
        currentPosition.board.moveGeneration();

        if (currentPosition.board.checks)
            return (currentPosition.board.turn == TURN::white) ? Evaluation(GameStatus::BLACK_WINS, negInf) : Evaluation(GameStatus::WHITE_WINS, negInf);

        return Evaluation(GameStatus::DRAW);
    }

    // printf("4");
    return Evaluation(GameStatus::STILL_GOING, max_score);
}
