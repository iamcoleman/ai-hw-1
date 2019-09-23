//
// Created by Coleman on 9/17/2019.
//

#ifndef AI_HW_1_BFS_H
#define AI_HW_1_BFS_H

#include <queue>
#include <vector>
#include <list>

#include "Board.h"

class BFS {
public:
    // Constructor
    BFS();

    // Data Members
    bool goalFound;
    std::list<Board*> openList;
    std::vector<Board*> closedList;
    std::vector<Board*> trailOfBoards;

    // General Functions
    int positionOfTile(int num, const Board &board);
    bool isBoardInClosedList(Board *board);

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

    // BFS Functions
    void BreadthFirstSearch(Board *board);
    void CreateChildren(Board *board);
    void CreateBoardTrail(Board *board);
    void PrintBoardTrail();

};


#endif //AI_HW_1_BFS_H
