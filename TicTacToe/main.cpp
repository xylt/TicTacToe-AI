#include "Chessboard.h"

int main() {
    ChessBoard b;
    b.placeComp(0);
    b.placeHuman(8);
    b.unPlace(0);
    b.print();
    return 0;
}