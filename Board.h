//
// Created by Coleman on 9/16/2019.
//

#ifndef AI_HW_1_BOARD_H
#define AI_HW_1_BOARD_H


class Board {
public:
    static int nextid;  // id of the next board
    int id;             // id of board
    Board* parent;      // parent board
    Board* child[4];    // children boards
    int state[20];      // state of board
    int goalState[20];  // goal state
    int g_of_n;         // g(n) = the cost of making a move
    int h_of_n;         // h(n) = heuristic cost
    int f_of_n;         // f(n) = g(n) + h(n)

    Board(const int s[20], const int g[20]);   // Constructor
    Board(const Board &other);                 // Copy Constructor
    void printStateFancy();                    // print the current state ~fancy~

    // Operators
    friend bool operator ==(const Board& first, const Board& second);
    friend bool operator !=(const Board& first, const Board& second);

    // Computations
    bool isGoalState();
};


#endif //AI_HW_1_BOARD_H
