//
// Created by Coleman on 9/17/2019.
//

#ifndef AI_HW_1_BFS_H
#define AI_HW_1_BFS_H

#include <queue>
#include <vector>

#include "Board.h"

class BFS {
public:

    // Data Members
    bool goalFound;
    std::queue <Board> openList;
    std::vector< int( * )[20] > closedList;
    std::vector<Board> trailOfBoards;

    // General BFS functions
    int positionOfTile(int num, const Board &board);

    // Able to move tile functions
    typedef bool (BFS::*canMovePtr)(const Board &board);
    canMovePtr canMove[4];
    bool canMoveUp(const Board &board);
    bool canMoveDown(const Board &board);
    bool canMoveLeft(const Board &board);
    bool canMoveRight(const Board &board);

    // Move tile functions
    typedef void (BFS::*movePtr)(Board &board);
    movePtr moveBoard[4];
    void moveTile(int pos0, int pos1, Board &board);
    void moveUp(Board &board);
    void moveDown(Board &board);
    void moveLeft(Board &board);
    void moveRight(Board &board);

};


#endif //AI_HW_1_BFS_H
