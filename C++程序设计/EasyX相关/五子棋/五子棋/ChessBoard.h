#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <vector>

const int BOARD_SIZE = 15;

class ChessBoard {
private:
    std::vector<std::vector<int>> board;

public:
    ChessBoard();
    void initBoard();
    bool isEmpty(int row, int col);
    void makeMove(int row, int col, int player);
    int getCell(int row, int col);
};

#endif // CHESSBOARD_H