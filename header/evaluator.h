#include "position.h"
#include "defination.h"
#include <fstream>

class Evaluator
{
public:
    std::string dataFileName;
    std::array<double, 777> coefficients;
    double intercept;

    Evaluator(std::string file = DATA_FILE::defaultModelDataFileName)
    {
        dataFileName = file;

        readDataFile();
    }

    void readDataFile()
    {
        std::ifstream infile(dataFileName);
        std::string line;
        std::getline(infile, line);

        std::istringstream iss(line);
        double value;
        int it = 0;

        while (iss >> value)
        {
            if (it == 777)
            {
                intercept = value;
                break;
            }

            coefficients[it] = value;
            it++;
        }
    }

    void printModel()
    {
        std::cout << "\nCoefficients :\n";

        for (int i = 0; i < 777; i++)
        {
            std::cout << coefficients[i] << " ";
        }

        std::cout << "\nIntercept : " << intercept << std::endl;
    }

    double evaluate(Position position)
    {
        std::array<double, 777> parameters = translator(position);

        double result = intercept;

        for (int i = 0; i < 777; i++)
        {
            result += coefficients[i] * parameters[i];
        }

        return result;
    }

    std::array<double, 777> translator(Position position)
    {
        std::array<double, 777> data;

        int it = 0;

        data[it] = position.moveNum;
        it++;
        data[it] = position.board.turn;
        it++;
        data[it] = position.board.checks;
        it++;
        data[it] = position.board.castle[BOARD::whiteKingSideCastleIndex];
        it++;
        data[it] = position.board.castle[BOARD::whiteQueenSideCastleIndex];
        it++;
        data[it] = position.board.castle[BOARD::blackKingSideCastleIndex];
        it++;
        data[it] = position.board.castle[BOARD::blackQueenSideCastleIndex];
        it++;
        data[it] = position.board.fiftyMoves;
        it++;
        data[it] = position.board.materialBalance;
        it++;

        for (int rank = 0; rank < 8; rank++)
        {
            for (int file = 0; file < 8; file++)
            {
                Piece *piece = position.board.boardIndex({rank, file});

                int WWatchers = 0, BWatchers = 0, EWatching = 0, WWatching = 0, BWatching = 0, KWatching = 0;

                for (auto x : piece->watchers)
                {
                    if (position.board.boardIndex(x.first)->color == COLOR::white)
                        WWatchers++;
                    else if (position.board.boardIndex(x.first)->color == COLOR::black)
                        BWatchers++;
                    else
                        std::cout << "error in watchers" << std::endl;
                }

                for (auto x : piece->watchingSquare)
                {
                    for (auto y : x.second)
                    {
                        if (position.board.boardIndex(y)->color == position.board.turn && position.board.boardIndex(y)->pieceType == PIECE::KING)
                            KWatching++;
                        else if (position.board.boardIndex(y)->color == COLOR::white)
                            WWatching++;
                        else if (position.board.boardIndex(y)->color == COLOR::black)
                            BWatching++;
                        else if (position.board.boardIndex(y)->color == COLOR::nothing)
                            EWatching++;
                        else
                            std::cout << "error in watching square" << std::endl;
                    }
                }

                data[it] = (piece->pieceType == PIECE::PAWN);
                it++;
                data[it] = (piece->pieceType == PIECE::KNIGHT);
                it++;
                data[it] = (piece->pieceType == PIECE::BISHOP || piece->pieceType == PIECE::QUEEN);
                it++;
                data[it] = (piece->pieceType == PIECE::ROOK || piece->pieceType == PIECE::QUEEN);
                it++;
                data[it] = (piece->pieceType == PIECE::KING);
                it++;
                data[it] = piece->color;
                it++;
                data[it] = WWatchers;
                it++;
                data[it] = BWatchers;
                it++;
                data[it] = EWatching;
                it++;
                data[it] = WWatching;
                it++;
                data[it] = BWatching;
                it++;
                data[it] = KWatching;
                it++;
            }
        }

        return data;
    }
};
