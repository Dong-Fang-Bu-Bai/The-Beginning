#include "ChessBoard.h"

ChessBoard::ChessBoard() {
    initBoard();
}

void ChessBoard::initBoard() {
    board.clear();
    board.resize(BOARD_SIZE, std::vector<int>(BOARD_SIZE, 0));
}

bool ChessBoard::isEmpty(int row, int col) {
    return board[row][col] == 0;
}

void ChessBoard::makeMove(int row, int col, int player) {
    board[row][col] = player;
}

int ChessBoard::getCell(int row, int col) {
    return board[row][col];
}