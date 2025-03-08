#pragma once

/*
 * 棋盘逻辑核心类
 * 职责：
 * 1. 维护棋盘二维数组状态
 * 2. 实现落子合法性校验
 * 3. 处理胜负判定逻辑
 * 4. 提供棋盘重置功能
 * 数据结构：
 * - 使用二维数组存储棋子位置
 * - 当前玩家状态跟踪
 * 协作模块：
 * - 被GameManager调用进行逻辑判断
 * - 为GraphicsManager提供渲染数据
 */
class ChessBoard {
public:
    static const int BOARD_SIZE = 15;
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    int currentPlayer = 1;

public:
    ChessBoard();
    bool placePiece(int x, int y);
    bool checkWin(int x, int y) const;
    int getCurrentPlayer() const;
    void reset();
};