#pragma once

/*
Class for AI algorithms
*/

class ChessBoard;

class AI {
public:
    // Get computer's best movement
    static int getBestMove(ChessBoard &board);
private:
    // Find computer's best movement
    // using minimax algorithm and alpha-beta pruning
    static void findCompMove(ChessBoard &board, int &bestMove,
        int &value, int alpha, int beta);

    // Find human's best movement
    // using minimax algorithm and alpha-beta pruning
    static void findHumanMove(ChessBoard &board, int &bestMove,
        int &value, int alpha, int beta);

    // Constants of @param value in the above two methods
    static const int CompWin = 2;
    static const int Draw = 1;
    static const int CompLoss = 0;
};
