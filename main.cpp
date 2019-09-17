//
// Created by Coleman on 9/16/2019.
//

#include <iostream>
#include "Board.h"

using namespace std;

int main() {
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~" << endl << "~~~ 19-Tile Puzzle ~~~" << endl << "~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

    int startArray[20] = { 9, 16, 19, 0, 2, 6, 1, 17, 12, 15, 14, 7, 11, 10, 13, 18, 8, 5, 4, 3 };
    int goalArray[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0 };

    Board board(startArray, goalArray);

    board.printStateFancy();

    return 0;
}
