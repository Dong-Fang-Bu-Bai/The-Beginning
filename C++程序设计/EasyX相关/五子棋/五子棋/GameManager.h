#pragma once
#include "ChessBoard.h"
#include "GraphicsManager.h"
#include "GameState.h"

/*
 * 游戏控制核心类
 * 职责：
 * 1. 管理游戏生命周期（开始、运行、重启）
 * 2. 协调图形模块与棋盘逻辑的交互
 * 3. 处理用户输入事件
 * 4. 维护游戏状态机（主菜单/游戏中/暂停菜单）
 * 依赖：
 * - ChessBoard 处理游戏逻辑
 * - GraphicsManager 处理图形渲染
 */
class GameManager {
private:
    ChessBoard board;
    GraphicsManager graphics;
    bool gameRunning = true;
    ::GameState currentState = ::GameState::MAIN_MENU;

    void processInput();
    void updateGameState();
    void renderGame();
    void drawMainMenu();
    void drawPauseMenu();
    bool checkButtonClick(int x, int y, int btnX, int btnY, int width, int height);

public:
    void startGame();
    void restartGame();
};