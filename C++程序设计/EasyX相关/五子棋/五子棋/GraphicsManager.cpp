#include "GraphicsManager.h"
#include <locale.h>

GraphicsManager::GraphicsManager() {
    cellSize = windowSize / ChessBoard::BOARD_SIZE;
}

int GraphicsManager::getCellSize() const {
    return cellSize;
}

GraphicsManager::~GraphicsManager() {
    closegraph();
}

void GraphicsManager::initWindow() {
    initgraph(windowSize, windowSize);
    setbkcolor(boardColor);
    cleardevice();
}

/*
 * 棋盘网格绘制方法
 * 功能：
 * 1. 设置棋盘线颜色
 * 2. 绘制BOARD_SIZE+1条水平/垂直线
 * 3. 根据cellSize计算线条位置
 * 设计要点：
 * - 使用EasyX图形库line函数
 * - 线条间距由cellSize动态计算
 */
void GraphicsManager::drawGrid() 
{
    setlinecolor(lineColor);
    for (int i = 0; i <= ChessBoard::BOARD_SIZE; i++)
    {
        // 绘制水平线
        line(0, i*cellSize, windowSize, i*cellSize);
        // 绘制垂直线
        line(i*cellSize, 0, i*cellSize, windowSize);
    }
}

/*
 * 棋子绘制方法
 * 功能：
 * 1. 根据玩家选择棋子颜色
 * 2. 计算棋盘坐标到像素坐标的转换
 * 3. 绘制带边框的圆形棋子
 * 坐标计算：
 * - 棋盘坐标(x,y)转换为像素中心点坐标
 * - 公式：x_pixel = cellSize/2 + x*cellSize
 */
// 提取重复的计算逻辑
const int halfCellSize = getCellSize() / 2;
void GraphicsManager::drawPiece(int x, int y, int player) 
{
    COLORREF pieceColor = (player == 1) ? BLACK : WHITE;
    setfillcolor(pieceColor);
    fillcircle(halfCellSize + x * getCellSize(), halfCellSize + y * getCellSize(), halfCellSize - 2);
}

/*
 * 棋盘更新方法
 * 功能：
 * 1. 清空画布后重绘棋盘
 * 2. 遍历棋盘二维数组绘制所有棋子
 * 协作模块：
 * - 调用ChessBoard获取棋盘状态
 * - 调用drawGrid和drawPiece完成绘制
 */
void GraphicsManager::updateBoard( ChessBoard& board)
{
    cleardevice();
    drawGrid();
    for (int i = 0; i < ChessBoard::BOARD_SIZE; i++) {
        for (int j = 0; j < ChessBoard::BOARD_SIZE; j++) {
            if (board.board[i][j] != 0) {
                drawPiece(i, j, board.board[i][j]);
            }
        }
    }
}

void GraphicsManager::showWinner(int winner) {
    settextcolor(winner == 1 ? BLACK : WHITE);
    settextstyle(50, 0, L"Microsoft YaHei");
    _wsetlocale(LC_ALL, L"chs");
    int textW = textwidth(winner == 1 ? L"black" : L"white");
    int textH = textheight(winner == 1 ? L"black" : L"white");
    outtextxy(windowSize/2 - textW/2 + this->xOffset, windowSize/2 - textH/2 + this->yOffset, winner == 1 ? L"Black win!" : L"White win!");
}

MOUSEMSG GraphicsManager::getMouseInput() {
    return GetMouseMsg();
}