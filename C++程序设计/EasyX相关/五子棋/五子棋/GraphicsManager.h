#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include "ChessBoard.h"

class GraphicsManager {
private:
    ChessBoard& chessBoard;

public:
    GraphicsManager(ChessBoard& board);
    void drawBoard();
};

#endif // GRAPHICSMANAGER_H