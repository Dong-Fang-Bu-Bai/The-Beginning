#include "ChessBoard.h"

ChessBoard::ChessBoard() {
    reset();
}

bool ChessBoard::placePiece(int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE || board[x][y] != 0)
        return false;
    
    board[x][y] = currentPlayer;
    currentPlayer = 3 - currentPlayer;
    return true;
}

bool ChessBoard::checkWin(int x, int y) const {
    const int directions[4][2] = {{1,0}, {0,1}, {1,1}, {1,-1}};
    int player = board[x][y];

    for (auto& dir : directions) {
        int count = 1;
        for (int i = 1; i < 5; i++) {
            int nx = x + dir[0] * i;
            int ny = y + dir[1] * i;
            if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && board[nx][ny] == player)
                count++;
            else
                break;
        }
        for (int i = 1; i < 5; i++) {
            int nx = x - dir[0] * i;
            int ny = y - dir[1] * i;
            if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && board[nx][ny] == player)
                count++;
            else
                break;
        }
        if (count >= 5)
            return true;
    }
    return false;
}

int ChessBoard::getCurrentPlayer() const {
    return currentPlayer;
}

void ChessBoard::reset() {
    for (auto& row : board)
        for (auto& cell : row)
            cell = 0;
    currentPlayer = 1;
}