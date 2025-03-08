#include "GameManager.h"
#include <iostream>

/*
 * 游戏主循环
 * 功能：
 * 1. 初始化图形窗口
 * 2. 维护游戏循环（输入->更新->渲染）
 * 3. 协调各模块工作流程
 * 调用关系：
 * - 被main函数调用
 * - 调用processInput/updateGameState/renderGame
 */
void GameManager::startGame() {
    graphics.initWindow();
    while (gameRunning) {
        processInput();
        updateGameState();
        renderGame();
    }
}

void GameManager::drawMainMenu() {
    cleardevice();
    settextstyle(40, 0, L"Microsoft YaHei");
    settextcolor(BLACK);
    
    // 绘制标题
    outtextxy(180, 100, L"Gomoku");
    
    // 绘制按钮
    setfillcolor(RGB(200, 200, 200));
    fillroundrect(200, 200, 400, 300, 10, 10);
    outtextxy(230, 240, L"Start Game");
    
    fillroundrect(200, 320, 400, 420, 10, 10);
    outtextxy(235, 360, L"Leaderboard");
    
    fillroundrect(200, 440, 400, 540, 10, 10);
    outtextxy(240, 480, L"Exit Game");
}

bool GameManager::checkButtonClick(int x, int y, int btnX, int btnY, int width, int height) {
    return x > btnX && x < btnX + width && y > btnY && y < btnY + height;
}

/*
 * 输入处理核心方法
 * 功能：
 * 1. 处理鼠标点击事件
 * 2. 根据游戏状态分发事件
 * 3. 实现状态切换逻辑
 * 设计思想：
 * - 使用状态模式处理不同界面交互
 * - 通过坐标检测实现按钮响应
 */
void GameManager::processInput() 
{
    MOUSEMSG msg = graphics.getMouseInput();
    if (msg.uMsg == WM_LBUTTONDOWN)
    {
        if (currentState == GameState::MAIN_MENU)
        {
            if (checkButtonClick(msg.x, msg.y, 200, 200, 200, 100))
            {
                std::cout << "start" << std::endl;
                currentState = GameState::IN_GAME;
                board.reset();
            }
            else if (checkButtonClick(msg.x, msg.y, 200, 400, 200, 100))
            {
                std::cout << "exit" << std::endl;
                gameRunning = false;
            }
            return;
        }
        else if (currentState == GameState::PAUSE_MENU)
        {
            if (checkButtonClick(msg.x, msg.y, 200, 200, 200, 100))
            {
                currentState = GameState::IN_GAME;
            }
            else if (checkButtonClick(msg.x, msg.y, 200, 320, 200, 100))
            {
                currentState = GameState::MAIN_MENU;
            }
            else if (checkButtonClick(msg.x, msg.y, 200, 440, 200, 100))
            {
                gameRunning = false;
            }
            std::cout << "click:" << msg.x << "," << msg.y << std::endl;
            return;
        }
        else if (currentState == GameState::IN_GAME)
        {
            // 暂停按钮坐标常量
            const int btnX1 = 20, btnY1 = 20;
            const int btnX2 = 80, btnY2 = 80;
            
            // 暂停按钮点击检测
            if(msg.x >= btnX1 && msg.x <= btnX2 && msg.y >= btnY1 && msg.y <= btnY2)
            {
                
                std::cout << "vivid:" << btnX1 << "," << btnY1 << " - " 
                    << btnX2 << "," << btnY2 << std::endl;
                currentState = GameState::PAUSE_MENU;
                
                return;
            }
            /*else 
            {
                std::cout << "click:" << msg.x << "," << msg.y << std::endl;
            }*/
            
            // 增加浮点转换确保精度
            float cellSize = static_cast<float>(graphics.getCellSize());
            float offset = cellSize / 2.0f;
            // 添加偏移量验证
            std::cout << "cellSize=" << cellSize << std::endl;
            std::cout << "Raw coordinates: x=" << msg.x << ", y=" << msg.y << std::endl;
            std::cout << "Using offset: " << offset << std::endl;
            // 移除整数offset定义，使用已计算的浮点offset
            std::cout << "Calculating gridX: (" << msg.x << " - " << offset << ")/" << graphics.getCellSize() << " = " << (msg.x - offset) / graphics.getCellSize() << std::endl;
            int gridX = static_cast<int>((msg.x - offset) / cellSize + 0.5f);

            std::cout << "Calculating gridY: (" << msg.y << " - " << offset << ")/" << cellSize << " = " << (msg.y - offset) / cellSize << std::endl;
            int gridY = static_cast<int>((msg.y - offset) / cellSize + 0.5f);
            std::cout << "Clicked at (" << msg.x << "," << msg.y << ") -> grid(" << gridX << "," << gridY << ")" << std::endl;
            // 增加坐标有效性检查
            if (gridX >= 0 && gridX < ChessBoard::BOARD_SIZE && gridY >= 0 && gridY < ChessBoard::BOARD_SIZE)
            {
                if (board.placePiece(gridX, gridY))
                {
                    if (board.checkWin(gridX, gridY))
                    {
                        graphics.showWinner(3 - board.getCurrentPlayer());
                        Sleep(2000);
                        restartGame();
                    }
                }
            }
        }
    }
}

void GameManager::updateGameState() {}




/*
 * 渲染调度方法
 * 功能：
 * 1. 根据当前状态调用对应渲染器
 * 2. 维护界面元素统一风格
 * 3. 实现暂停按钮动态绘制
 * 协作模块：
 * - 调用GraphicsManager更新棋盘显示
 */
void GameManager::renderGame()
{
    switch(currentState) 
    {
        case GameState::MAIN_MENU:
            drawMainMenu();
            break;
        case GameState::IN_GAME:
            graphics.updateBoard(board);
            setfillcolor(RGB(200, 200, 200));
            fillrectangle(20, 20, 80, 80);
            settextcolor(BLACK);
            settextstyle(20, 0, L"Microsoft YaHei");
            outtextxy(25, 40, L"Pause");
            break;
        case GameState::PAUSE_MENU:
            drawPauseMenu();
            break;
    }
}





void GameManager::drawPauseMenu() 
{
    cleardevice();
    settextstyle(40, 0, L"Microsoft YaHei");
    settextcolor(BLACK);
    
    // 绘制标题
    outtextxy(180, 100, L"Game Paused");
    
    // 绘制按钮
    setfillcolor(RGB(200, 200, 200));
    // 调整按钮高度为100像素
    fillroundrect(200, 200, 400, 300, 10, 10);
    outtextxy(220, 240, L"Resume Game");
    fillroundrect(200, 320, 400, 420, 10, 10);
    outtextxy(240, 360, L"Main Menu");
    fillroundrect(200, 440, 400, 540, 10, 10);
    outtextxy(240, 480, L"Exit Game");
}
    


void GameManager::restartGame()
{
    board.reset();
    graphics.updateBoard(board);
}
   
          
   
