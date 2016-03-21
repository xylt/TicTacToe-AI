#include "Game.h"
#include "AI.h"
#include <iostream>
using namespace std;

void Game::start() {
    Role firstPlace = chooseFirstPlace();
    if (firstPlace == COMP) {  // Choose computer to be the first
        compPlace();
    }
    while (1) {
        printBoard();
        if (handleGameOver()) break;
        humanPlace();
        printBoard();
        if (handleGameOver()) break;
        compPlace();
    }
}

Game::Role Game::chooseFirstPlace() {
    int choice;
    while (1) {
        cout << "Who will place the first piece?" << endl;
        cout << "0->Human first" << endl;
        cout << "1->Computer first" << endl;
        cin >> choice;
        if (choice == 0 || choice == 1) {
            cout << endl;
            break;
        }
    }
    return (Role)choice;
}

void Game::printBoard() {
    board.print();
}

int Game::getPlacePosition() {
    string input;
    while (1) {
        cout << "It's your turn. Where to place the chess piece?" << endl;
        cout << "(Typing 22 means place at row 2, column 2):" << endl;
        cin >> input;
        if (isLegalPlacePosition(input)) {
            cout << endl;
            break;
        } else {
            cout << "Your input format is illegal. Please try again." << endl;
        }
    }
    // Change coordinate to one-dimension
    return convertInputToPosition(input);
}

bool Game::isLegalPlacePosition(const string &input) {
    return input.size() == 2 && input[0] >= '1' && input[0] <= '3'
        && input[1] >= '1' && input[1] <= '3'
        && board.isEmpty(convertInputToPosition(input));
}

int Game::convertInputToPosition(const string &input) {
    return (input[0] - '0' - 1) * 3 + (input[1] - '0' - 1);
}

void Game::humanPlace() {
    int pos = getPlacePosition();
    board.placeHuman(pos);
    cout << "Your choice:" << endl;
}

void Game::compPlace() {
    int bestMove = 0, value = 0;
    AI::findCompMove(board, bestMove, value);
    board.placeComp(bestMove);
    cout << "The computer's choice:" << endl;
}

bool Game::gameIsOver(bool &draw, Role &win) {
    if (board.compWin()) {
        win = COMP;
        draw = false;
        return true;
    } else if (board.humanWin()) {
        win = HUMAN;
        draw = false;
        return true;
    } else if (board.isFull()) {
        draw = true;
        return true;
    } else {
        return false;
    }
}

bool Game::handleGameOver() {
    bool draw = false;
    Role whoWin = HUMAN;
    if (gameIsOver(draw, whoWin)) {
        if (draw) {
            cout << "Draw!" << endl;
        } else {
            if (whoWin == COMP) {
                cout << "You lose!" << endl;
            } else if (whoWin == HUMAN) {
                cout << "Congratualtions! You defeat the computer." << endl;
            }
        }
        return true;
    } else {
        return false;
    }
}
