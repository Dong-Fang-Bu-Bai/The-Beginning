#include "GameManager.h"
#include <iostream>

GameManager::GameManager(ChessBoard& board) : chessBoard(board), currentPlayer(1) {}

bool GameManager::makeMove(int row, int col) {
    if (chessBoard.isEmpty(row, col)) {
        chessBoard.makeMove(row, col, currentPlayer);
        return true;
    }
    return false;
}

bool GameManager::checkWin(int row, int col) {
    // 简单示例，未实现完整的胜负判断逻辑
    return false;
}

int GameManager::getCurrentPlayer() {
    return currentPlayer;
}

void GameManager::switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}
   
          
   
