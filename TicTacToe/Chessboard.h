#pragma once

/*
Class for the chessboard of the game
*/

#define CHESSBOARD_ROW 13
#define CHESSBOARD_COLUMN 26
#define GRID_NUMBER 9

class ChessBoard {
public:
    ChessBoard();

    // Place a human chess piece at the chessboard
    // pos is from 0 to 8
    void placeHuman(const int pos);

    // Place a computer chess piece at the chessboard
    // pos is from 0 to 8
    void placeComp(const int pos);

    // Unplace a chess piece at the chessboard
    // pos is from 0 to 8
    void unPlace(const int pos);

    // Prin the board to console
    void print();

private:
    // The board one-dimension used for calculation
    char boardInOneDimens[GRID_NUMBER];

    // The board two-dimension array to be printed to console
    char board[CHESSBOARD_ROW][CHESSBOARD_COLUMN] = {
        "- - - - - - - - - - - - -",
        "|       |       |       |",
        "|       |       |       |",
        "|       |       |       |",
        "- - - - - - - - - - - - -",
        "|       |       |       |",
        "|       |       |       |",
        "|       |       |       |",
        "- - - - - - - - - - - - -",
        "|       |       |       |",
        "|       |       |       |",
        "|       |       |       |",
        "- - - - - - - - - - - - -"
    };
};
