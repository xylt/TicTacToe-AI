#include "AI.h"
#include "Chessboard.h"

void AI::findCompMove(ChessBoard &board, int &bestMove,
    int &value, int alpha, int beta) {
    if (board.isFull()) {
        value = Draw;
    } else if (board.compWinImmediately(bestMove)) {
        value = CompWin;
    } else {
        // TODO Place chess pieces at valid postion to get bestmove
    }
}

void AI::findHumanMove(ChessBoard &board, int &bestMove,
    int &value, int alpha, int beta) {
    if (board.isFull()) {
        value = Draw;
    } else if (board.humanWinImmediately(bestMove)) {
        value = CompLoss;
    } else {
        // TODO Place chess pieces at valid postion to get bestmove
    }
}
