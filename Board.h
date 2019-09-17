//
// Created by Coleman on 9/16/2019.
//

#ifndef AI_HW_1_BOARD_H
#define AI_HW_1_BOARD_H


class Board {
public:
    int id;             // id of board
    Board* parent;      // parent board
    Board* child[4];    // children boards
    int state[20];      // state of board
    int goalState[20];  // goal state
    int g_of_n;         // g(n)
    int h_of_n;         // h(n)
    int f_of_n;         // f(n) = g(n) + h(n)

    Board(const int s[20], const int g[20], Board* p_id = nullptr);   // Constructor
    void printStateFancy();                                           // print the current state ~fancy~
    void printGoalStateFancy();                                       // print the goal state ~fancy~

    // Operators
    friend bool operator ==(const Board& first, const Board& second);
    friend bool operator !=(const Board& first, const Board& second);

    // Getters
    int getId();
    Board* getParent();
    int* getState();
    int* getGoalState();
    int get_f_of_n();

    // Computations
    bool isGoalState();

};


#endif //AI_HW_1_BOARD_H
