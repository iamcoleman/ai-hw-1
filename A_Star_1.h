//
// Created by Coleman on 9/23/2019.
//

#ifndef AI_HW_1_A_STAR_1_H
#define AI_HW_1_A_STAR_1_H

#include <queue>
#include <vector>
#include <list>

#include "Board.h"


class A_Star_1 {
    // Constructor
    A_Star_1();

    // Data Members
    bool goalFound;
    std::list<Board*> openList;
    static int openListTotalAdds;
    std::vector<Board*> closedList;
    static int closedListTotalAdds;
    std::vector<Board*> trailOfBoards;

    // General Functions
    int positionOfTile(int num, const Board &board);
    bool isBoardInClosedList(Board *board);

    // Able to move tile functions
    typedef bool (A_Star_1::*canMovePtr)(const Board &board);
    canMovePtr canMove[4];
    bool canMoveUp(const Board &board);
    bool canMoveDown(const Board &board);
    bool canMoveLeft(const Board &board);
    bool canMoveRight(const Board &board);

    // Move tile functions
    typedef void (A_Star_1::*movePtr)(Board &board);
    movePtr moveBoard[4];
    void moveTile(int pos0, int pos1, Board &board);
    void moveUp(Board &board);
    void moveDown(Board &board);
    void moveLeft(Board &board);
    void moveRight(Board &board);

    // A* functions
};


#endif //AI_HW_1_A_STAR_1_H
