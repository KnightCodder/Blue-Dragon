#include "analyzer.h"

void compilingPieceVision();

int main()
{
    compilingPieceVision();

    std::string cache;

    std::string startingFen = BOARD::defaultFen;
    std::cout << "do you want to provide a FEN (y/n) : ";
    std::cin >> cache;
    if (cache == "y" || cache == "Y")
    {
        std::cout << "\nenter FEN : ";
        std::cin.ignore();
        std::getline(std::cin, startingFen);
    }

    int turn = TURN::white;
    std::cout << "\nfrom which side do you want to play (w/b) : ";
    std::cin >> cache;
    if (cache == "b" || cache == "B")
        turn = TURN::black;

    ANALYZE analyzingBoard(startingFen, 2);

    while (true)
    {
        analyzingBoard.currentPosition.board.printBoard();
        std::cout << "----------------------------------------------------" << std::endl;

        Move bestMove = analyzingBoard.bestMove();
        // std::cout << analyzingBoard.currentPosition.board.turn << std::endl;

        if (analyzingBoard.isGameOver)
        {
            std::cout << "GAME OVER" << std::endl;
            break;
        }

        if (analyzingBoard.currentPosition.board.turn == turn)
        {
            std::cout << "enter a move : ";
            std::cin >> cache;
            
            analyzingBoard.playMove(analyzingBoard.currentPosition.board.notationsToIndex(cache));
        }
        else if (analyzingBoard.currentPosition.board.turn == -turn)
        {
            analyzingBoard.playMove(bestMove);
            std::cout << "computer played :- ";
            bestMove.print();
        }
        else
            std::cout << "why the fuck" << std::endl;
    }

    return 0;
}
