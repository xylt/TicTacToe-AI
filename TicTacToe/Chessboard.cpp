#include "Chessboard.h"
#include "Constants.h"
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
        printf("%s\n", board[i]);
    }
}

bool ChessBoard::isFull() {
    for (int i = 0; i < GRID_NUMBER; ++i) {
        if (boardInOneDimens[i] == BLANK_CHAR) {
            return false;
        }
    }
    return true;
}


bool ChessBoard::compWinImmediately(int pos) {
    if (boardInOneDimens[pos] != BLANK_CHAR) return false;
    boardInOneDimens[pos] = COMP_CHAR;
    bool win = compWin();
    boardInOneDimens[pos] = BLANK_CHAR;
    return win;
}

bool ChessBoard::humanWinImmediately(int pos) {
    if (boardInOneDimens[pos] != BLANK_CHAR) return false;
    boardInOneDimens[pos] = HUMAN_CHAR;
    bool win = humanWin();
    boardInOneDimens[pos] = BLANK_CHAR;
    return win;
}


bool ChessBoard::compWin() {
    return hasWon(COMP_CHAR);
}

bool ChessBoard::humanWin() {
    return hasWon(HUMAN_CHAR);
}

bool ChessBoard::hasWon(char c) {
    // Check rows
    for (int i = 0; i <= 6; i += 3)
        return boardInOneDimens[i] == c && boardInOneDimens[i] == boardInOneDimens[i + 1]
        && boardInOneDimens[i] == boardInOneDimens[i + 2];

    // Check columns
    for (int i = 0; i <= 3; ++i)
        return boardInOneDimens[i] == c && boardInOneDimens[i] == boardInOneDimens[i + 3]
        && boardInOneDimens[i] == boardInOneDimens[i + 6];

    // Check diagonals
    return boardInOneDimens[4] == c && boardInOneDimens[0] == boardInOneDimens[4]
        && boardInOneDimens[0] == boardInOneDimens[8];

    return boardInOneDimens[4] == c && boardInOneDimens[2] == boardInOneDimens[4]
        && boardInOneDimens[2] == boardInOneDimens[6];
}