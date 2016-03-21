#pragma once

#include "Chessboard.h"

#include <string>

class Game {
public:
    enum Role {HUMAN, COMP};

    // Start game
    void start();
private:
    ChessBoard board;

    // Choose the one who places the first piece
    // Return 0 means human-first, 1 means computer-first.
    Role chooseFirstPlace();

    // Print chess board
    void printBoard();

    // Ask user where to place a chess piece
    // Return the postion to place the chess piece
    int getPlacePosition();

    // Ask human to place the chess piece
    void humanPlace();

    // Computer decides where to place the chess piece
    void compPlace();

    // Judge if game is over
    // Return true if the game is over, and if @param draw
    // equals true, the @param win is useless.
    bool gameIsOver(bool &draw, Role &win);

    // If game is over, handle it
    // Return true means game is over.
    bool handleGameOver();

    // Judge if the input in getPlacePosition() is legal.
    // The input must be a string of length 2.
    // Input[0] means the row position
    // Input[1] means the column position
    bool isLegalPlacePosition(const std::string &input);

    // Convert the user's input to position in one-dimension array;
    int convertInputToPosition(const std::string &input);
};
