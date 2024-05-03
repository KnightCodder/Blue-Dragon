#include "position.h"
#include "defination.h"
#include <stack>
#include <limits>

struct Evaluation
{
    GameStatus status;
    double eval;

    Evaluation(GameStatus s = GameStatus::NOT_SURE, double e = 0)
    {
        status = s;
        eval = e;
    }
};

class ANALYZE
{
public:
    std::stack<Position> searchTree;
    std::map<Position, int> ThreeFoldRepetition = {};
    Position currentPosition;
    int maxDepth;
    std::pair<INDEX,INDEX> bestmove;
    Evaluation evaluation;

    ANALYZE(std::string startingFen, int maxdepth)
    {
        maxDepth = maxdepth;
        currentPosition = Position(Board(startingFen));
    }

    Evaluation negamax(int depth, double alpha, double beta);

    Move bestMove();
};