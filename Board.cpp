//
// Created by Coleman on 9/16/2019.
//

#include <iostream>
#include "Board.h"

using namespace std;

// setting static members
int Board::nextid = 1;
int Board::g_of_n = 1;
int Board::h_of_n = 0;
int Board::f_of_n = 1;
int Board::priorityValue = 1;

// Parametrized Constructor
Board::Board(const int *s, const int *g) {
    // set the id and increment the nextid
    id = nextid;
    ++nextid;

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
    // set the id and increment the nextid
    id = nextid;
    ++nextid;

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
    // print Board ID
    cout << "-- Board: " << id << endl;

    // print parent Board ID
    if (parent) {
        cout << "-- Parent Board: " << parent->id << endl;
    }

    // print g(n) value
    cout << "-- g(n) = " << g_of_n << endl;

    // print h(n) value
    cout << "-- h(n) = " << h_of_n << endl;

    // print f(n) value
    cout << "-- f(n) = " << f_of_n << endl;

    // print priority value
    cout << "-- Priority Value = " << priorityValue << endl;

    // print state of Board
    cout << "-- State for Board " << id << endl;
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
    cout << endl;
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
