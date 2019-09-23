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
public:
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
    typedef int (A_Star_1::*movePtr)(Board &board);
    movePtr moveBoard[4];
    int moveTile(int pos0, int pos1, Board &board);
    int moveUp(Board &board);
    int moveDown(Board &board);
    int moveLeft(Board &board);
    int moveRight(Board &board);

    // A* functions
    void aStarSearch(Board *board);
    void createChildren(Board *board);
    void setFunctionValues(Board *board, int tileNumber);
    int getHeuristicScore(Board *board);
    void insertBoardToPriorityQueue(Board *board);
    void createBoardTrail(Board *board);
    void printBoardTrail();
};


#endif //AI_HW_1_A_STAR_1_H
