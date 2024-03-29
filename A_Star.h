//
// Created by Coleman on 9/23/2019.
//

#ifndef AI_HW_1_A_STAR_H
#define AI_HW_1_A_STAR_H

#include <queue>
#include <vector>
#include <list>

#include "Board.h"


class A_Star {
public:
    // Constructor
    A_Star(int heuristic);

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
    typedef bool (A_Star::*canMovePtr)(const Board &board);
    canMovePtr canMove[4];
    bool canMoveUp(const Board &board);
    bool canMoveDown(const Board &board);
    bool canMoveLeft(const Board &board);
    bool canMoveRight(const Board &board);

    // Move tile functions
    typedef int (A_Star::*movePtr)(Board &board);
    movePtr moveBoard[4];
    int moveTile(int pos0, int pos1, Board &board);
    int moveUp(Board &board);
    int moveDown(Board &board);
    int moveLeft(Board &board);
    int moveRight(Board &board);

    // Heuristic functions
    typedef int (A_Star::*heuristicPtr)(Board &board);
    heuristicPtr heuristicFn;
    int getHeuristicScore1(Board &board);
    int getHeuristicScore2(Board &board);
    int getRowDifference(int tile, Board &board);
    int getColumnDifference(int tile, Board &board);

    // A* functions
    void aStarSearch(Board *board);
    void createChildren(Board *board);
    void setFunctionValues(Board *board, int tileNumber = 0);
    void insertBoardToPriorityQueue(Board *board);
    void createBoardTrail(Board *board);
    void printBoardTrail();

    // clean up
    void clearBoards();
    void clearBoards(Board* &root);
};


#endif //AI_HW_1_A_STAR_H
