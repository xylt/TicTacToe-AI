#include "Game.h"
#include <iostream>
using namespace std;

void Game::start() {
    int firstPlace = chooseFirstPlace();
    if (firstPlace == 1) {  // Choose computer to be the first

    }
}

int Game::chooseFirstPlace() {
    int choice;
    while (1) {
        cout << "Who will place the first piece?" << endl;
        cout << "0->Human first" << endl;
        cout << "1->Computer first" << endl;
        cin >> choice;
        if (choice == 0 || choice == 1) break;
    }
    return choice;
}
