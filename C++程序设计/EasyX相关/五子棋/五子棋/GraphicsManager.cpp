#include "GraphicsManager.h"
#include <graphics.h>

GraphicsManager::GraphicsManager(ChessBoard& board) : chessBoard(board) {}

void GraphicsManager::drawBoard() {
    // 简单示例，绘制棋盘网格
    for (int i = 0; i < BOARD_SIZE; ++i) {
        line(20, 20 + i * 30, 20 + (BOARD_SIZE - 1) * 30, 20 + i * 30);
        line(20 + i * 30, 20, 20 + i * 30, 20 + (BOARD_SIZE - 1) * 30);
    }
    // 绘制棋子
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (chessBoard.getCell(i, j) == 1) {
                setfillcolor(BLACK);
                solidcircle(20 + j * 30, 20 + i * 30, 12);
            } else if (chessBoard.getCell(i, j) == 2) {
                setfillcolor(WHITE);
                solidcircle(20 + j * 30, 20 + i * 30, 12);
            }
        }
    }
}