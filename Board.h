//
// Created by Coleman on 9/16/2019.
//

#ifndef AI_HW_1_BOARD_H
#define AI_HW_1_BOARD_H


class Board {

public:
    int id;
    int parent;
    int state[20];
    int g_of_n;
    int h_of_n;
    int f_of_n;

    explicit Board(int s[20]);
    void printStateFancy();
};


#endif //AI_HW_1_BOARD_H
