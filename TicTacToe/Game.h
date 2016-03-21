#pragma once

#include "Chessboard.h"

class Game {
public:
    // Start game
    void start();
private:
    ChessBoard board;

    // Choose the one who places the first piece
    // Return 0 means human-first, 1 means computer-first.
    int chooseFirstPlace();
};
