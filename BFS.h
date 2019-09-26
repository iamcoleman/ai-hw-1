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
    Board* rootBoard;
    bool goalFound;
    std::list<Board*> openList;
    int openListTotalAdds;
    std::vector<Board*> closedList;
    int closedListTotalAdds;
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
    typedef int (BFS::*movePtr)(Board &board);
    movePtr moveBoard[4];
    int moveTile(int pos0, int pos1, Board &board);
    int moveUp(Board &board);
    int moveDown(Board &board);
    int moveLeft(Board &board);
    int moveRight(Board &board);

    // BFS Functions
    void breadthFirstSearch(Board *board);
    void createChildren(Board *board);
    void setFunctionValues(Board *board, int tileNumber);
    void createBoardTrail(Board *board);
    void printBoardTrail();

    // clean up
    void clearBoards();
    void clearBoards(Board* &root);
};


#endif //AI_HW_1_BFS_H
