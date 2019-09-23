//
// Created by Coleman on 9/16/2019.
//

#include <iostream>
#include "Board.h"

using namespace std;

// Parametrized Constructor
Board::Board(const int *s, const int *g) {
    // set current state and goal state
    for (int i = 0; i < 20; ++i) {
        state[i] = s[i];
        goalState[i] = g[i];
    }

    // set parent
    parent = nullptr;

    // set children
    for (int j = 0; j < 4; ++j) {
        child[j] = nullptr;
    }
}

// Copy Constructor
Board::Board(const Board &other) {
    // set current state and goal state
    for (int i = 0; i < 20; ++i) {
        state[i] = other.state[i];
        goalState[i] = other.goalState[i];
    }

    // set parent to nullptr
    parent = nullptr;

    // set children to nullptr
    for (int j = 0; j < 4; ++j) {
        child[j] = nullptr;
    }
}

// Copy Assignment
Board &Board::operator=(const Board &other) {
    // set current state and goal state
    for (int i = 0; i < 20; ++i) {
        state[i] = other.state[i];
        goalState[i] = other.goalState[i];
    }

    // set parent to nullptr
    parent = other.parent;

    // set children to nullptr
    for (int j = 0; j < 4; ++j) {
        child[j] = other.child[j];
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
