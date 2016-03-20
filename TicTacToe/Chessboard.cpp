#include "Chessboard.h"
#include "Macros.h"
#include <iostream>
using namespace std;

ChessBoard::ChessBoard() {
    for (int i = 0; i < GRID_NUMBER; ++i) {
        boardInOneDimens[i] = BLANK_CHAR;
    }
}

void ChessBoard::placeHuman(const int pos) {
    if (pos >= 0 && pos <= 8) {
        boardInOneDimens[pos] = HUMAN_CHAR;
    }
}

void ChessBoard::placeComp(const int pos) {
    if (pos >= 0 && pos <= 8) {
        boardInOneDimens[pos] = COMP_CHAR;
    }
}

void ChessBoard::unPlace(const int pos) {
    if (pos >= 0 && pos <= 8) {
        boardInOneDimens[pos] = BLANK_CHAR;
    }
}

void ChessBoard::print() {
    int cnt = 0;
    for (int i = 2; i <= 10; i += 4) {
        for (int j = 4; j <= 20; j += 8) {
            board[i][j] = boardInOneDimens[cnt++];
        }
    }
    for (int i = 0; i < CHESSBOARD_ROW; ++i) {
        cout << board[i] << endl;
    }
}
