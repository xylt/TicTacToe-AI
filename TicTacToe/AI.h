#pragma once

/*
Class for AI algorithms
*/

class ChessBoard;

class AI {
public:
    // Find computer's best movement
    // using minimax algorithm and alpha-beta pruning
    static void findCompMove(ChessBoard &board, int &bestMove,
        int &value, int alpha, int beta);

private:
    // Find human's best movement
    // using minimax algorithm and alpha-beta pruning
    static void findHumanMove(ChessBoard &board, int &bestMove,
        int &value, int alpha, int beta);

    // Constants of @param value in the above two methods
    static const int CompWin = 2;
    static const int Draw = 1;
    static const int CompLoss = 0;
};
