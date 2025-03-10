#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "ChessBoard.h"

class GameManager {
private:
    ChessBoard& chessBoard;
    int currentPlayer;

public:
    GameManager(ChessBoard& board);
    bool makeMove(int row, int col);
    bool checkWin(int row, int col);
    int getCurrentPlayer();
    void switchPlayer();
};

#endif // GAMEMANAGER_H