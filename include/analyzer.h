#include "position.h"

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
    Position* searchTree;
    std::map<Position, int> ThreeFoldRepetition;
    Position currentPosition;
    int maxDepth;
    std::pair<INDEX,INDEX> bestMove;
    Evaluation evaluation;

    ANALYZE(std::string startingFen, int maxdepth)
    {
        maxDepth = maxdepth;
        searchTree = new Position[maxDepth];
        currentPosition = Position(Board(startingFen));
    }

    Evaluation negamax(int depth, double alpha, double beta);
};