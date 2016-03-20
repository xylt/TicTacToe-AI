#include "AI.h"
#include "Chessboard.h"

void AI::findCompMove(ChessBoard &board, int &bestMove,
    int &value, int alpha, int beta) {
    if (board.isFull()) {
        value = Draw;
    } else if (board.compWinImmediately(bestMove)) {
        value = CompWin;
    } else {
        value = alpha;
        for (int i = 0; i < 9 && value < beta; ++i) {
            if (board.isEmpty(i)) {
                board.placeComp(i);

                int tmp = 0, response = 0;
                findHumanMove(board, tmp, response, value, beta);

                board.unPlace(i);

                if (response > value) {
                    value = response;
                    bestMove = i;
                }
            }
        }
    }
}

void AI::findHumanMove(ChessBoard &board, int &bestMove,
    int &value, int alpha, int beta) {
    if (board.isFull()) {
        value = Draw;
    } else if (board.humanWinImmediately(bestMove)) {
        value = CompLoss;
    } else {
        value = beta;
        for (int i = 0; i < 9 && value > alpha; ++i) {
            if (board.isEmpty(i)) {
                board.placeHuman(i);

                int tmp = 0, response = 0;
                findCompMove(board, tmp, response, alpha, value);

                board.unPlace(i);

                if (response < value) {
                    value = response;
                    bestMove = i;
                }
            }
        }
    }
}
