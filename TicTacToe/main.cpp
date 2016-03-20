#include "Chessboard.h"

#include <iostream>
using namespace std;

int main() {
    ChessBoard b;
    for (int i = 0; i < GRID_NUMBER; ++i) {
        b.placeComp(i);
    }
    b.print();
    cout << b.humanWin() << endl;
    return 0;
}
