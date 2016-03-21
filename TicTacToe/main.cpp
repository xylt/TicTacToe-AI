#include "Chessboard.h"
#include "AI.h"

#include <iostream>
using namespace std;

int main() {
    ChessBoard b;
    b.placeHuman(4);
    //b.placeHuman(4);
    //b.placeComp(1);
    b.print();

    //int bestMove = -1;
    //b.humanCanWinImmediately(bestMove);
    //cout << bestMove << endl;

    int bestMove = -1, value = 0;
    AI::findCompMove(b, bestMove, value);
    cout << bestMove << endl;
    return 0;
}
