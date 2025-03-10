#include <graphics.h>
#include <iostream>
#include "ChessBoard.h"
#include "GameManager.h"
#include "GraphicsManager.h"

// 定义窗口大小
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main() {
    // 创建图形窗口
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);

    // 创建棋盘
    ChessBoard chessBoard;
    chessBoard.initBoard();

    // 创建游戏管理器
    GameManager gameManager(chessBoard);

    // 创建图形管理器
    GraphicsManager graphicsManager(chessBoard);
    graphicsManager.drawBoard();

    // 游戏主循环
    while (true) {
        // 处理鼠标事件
        MOUSEMSG msg = getmouse();
        if (msg.uMsg == WM_LBUTTONDOWN) {
            int x = msg.x;
            int y = msg.y;

            // 转换鼠标坐标为棋盘坐标
            int row = (y - 20) / 30;
            int col = (x - 20) / 30;

            // 落子
            if (gameManager.makeMove(row, col)) {
                // 更新棋盘显示
                graphicsManager.drawBoard();

                // 检查胜负
                if (gameManager.checkWin(row, col)) {
                    if (gameManager.getCurrentPlayer() == 1) {
                        outtextxy(300, 550, "黑方获胜！");
                    } else {
                        outtextxy(300, 550, "白方获胜！");
                    }
                    break;
                }

                // 切换玩家
                gameManager.switchPlayer();
            }
        }
    }

    // 等待用户按键关闭窗口
    getch();
    closegraph();

    return 0;
}