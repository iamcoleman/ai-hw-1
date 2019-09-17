//
// Created by Coleman on 9/16/2019.
//

#include <iostream>
#include "Board.h"
#include "BFS.h"

using namespace std;

// Parametrized Constructor
Board::Board(const int *s, const int *g, Board *p) {
    // set parent ID
    parent = p;

    // set current state
    for (int i = 0; i < 20; ++i) {
        state[i] = s[i];
    }

    // set goal state
    for (int j = 0; j < 20; ++j) {
        goalState[j] = g[j];
    }
}

/*
 * Operators
 */

bool operator==(const Board &first, const Board &second) {
    for (int i = 0; i < 20; ++i) {
        if (first.state[i] != second.state[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const Board &first, const Board &second) {
    int similar = 0;
    for (int i = 0; i < 20; ++i) {
        if (first.state[i] == second.state[i]) {
            similar++;
        }
    }
    return similar < 20;
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

void Board::printGoalStateFancy() {
    cout << "--- Goal State ---" << endl;
    for (int i = 0; i < 20; ++i) {
        if (goalState[i] < 10) {
            cout << goalState[i] << "   ";
        } else {
            cout << goalState[i] << "  ";
        }

        if (i == 3 || i == 7 || i == 11 || i == 15 || i == 19) {
            cout << endl;
        }
    }
}


/*
 * Getters
 */

int Board::getId() {
    return id;
}

Board* Board::getParent() {
    return parent;
}

int* Board::getState() {
    return state;
}

int* Board::getGoalState() {
    return goalState;
}

int Board::get_f_of_n() {
    return f_of_n;
}


/*
 * Computations
 */

bool Board::isGoalState() {
    for (int i = 0; i < 20; ++i) {
        if (state[i] != goalState[i]) {
            return false;
        }
    }
    return true;
}
