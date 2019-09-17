//
// Created by Coleman on 9/16/2019.
//

#include <iostream>
#include "Board.h"

using namespace std;

// Parametrized Constructor
Board::Board(int *s) {
    for (int i = 0; i < 20; ++i) {
        state[i] = s[i];
    }
}

void Board::printStateFancy() {
    cout << "--- State ---" << endl;
    for (int i = 0; i < 20; ++i) {
        if (state[i] < 10) {
            cout << state[i] << "   ";
        } else {
            cout << state[i] << "  ";
        }

        if (i == 3 || i == 7 || i == 11 || i == 15 || i == 19) {
            cout << endl;
        }
    }
}
