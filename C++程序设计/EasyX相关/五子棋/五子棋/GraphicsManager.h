#pragma once
#include <graphics.h>
#include "ChessBoard.h"

class GraphicsManager {
private:
    int windowSize = 600;
    int cellSize = 0;
    int xOffset = 0;
    int yOffset = 0;
    
    COLORREF boardColor = RGB(245, 222, 179);
    COLORREF lineColor = RGB(139, 69, 19);

    void drawGrid();
    void drawPiece(int x, int y, int player);

public:
    
    int getCellSize() const;
    GraphicsManager();
    ~GraphicsManager();
    void initWindow();
    void updateBoard( ChessBoard& board);
    void showWinner(int winner);
    MOUSEMSG getMouseInput();
};