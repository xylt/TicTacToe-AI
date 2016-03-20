#include "Chessboard.h"
#include "AI.h"

#include <iostream>
using namespace std;

int main() {
    ChessBoard b;
    /*for (int i = 0; i < GRID_NUMBER; ++i) {
        b.placeComp(i);
    }*/
    b.placeHuman(0);
    //b.placeComp(1);
    b.placeHuman(4);
    b.placeComp(2);
    b.placeComp(5);

    cout << b.compWinImmediately(1) << endl;

    int bestMove = 4, value;
    AI::findCompMove(b, bestMove, value);

    b.print();
    cout << bestMove << endl;
    return 0;
}
