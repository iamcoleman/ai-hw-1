//
// Created by Coleman on 9/17/2019.
//

#include <vector>
#include <iostream>

#include "BFS.h"

using namespace std;

// static ints
int BFS::openListTotalAdds = 0;
int BFS::closedListTotalAdds = 0;

/*
 * Constructor
 */

BFS::BFS()
{
    /*
     * For canMove and moveBoard
     * 0 = Up
     * 1 = Down
     * 2 = Left
     * 3 = Right
     */

    goalFound = false;

    // Pointers to can move functions
    canMove[0] = &BFS::canMoveUp;
    canMove[1] = &BFS::canMoveDown;
    canMove[2] = &BFS::canMoveLeft;
    canMove[3] = &BFS::canMoveRight;

    // Pointers to move functions
    moveBoard[0] = &BFS::moveUp;
    moveBoard[1] = &BFS::moveDown;
    moveBoard[2] = &BFS::moveLeft;
    moveBoard[3] = &BFS::moveRight;
}


/*
 * General functions
 */

int BFS::positionOfTile(int num, const Board &board) {
    for (int i = 0; i < 20; ++i) {
        if (board.state[i] == num) {
            return i;
        }
    }
    return -1;
}

bool BFS::isBoardInClosedList(Board *board) {
    for (vector<Board>::size_type i = 0; i != closedList.size(); i++) {
        if (*closedList[i] == *board) {
            return true;
        }
    }
    return false;
}


/*
 * Able to move tile functions
 */

bool BFS::canMoveUp(const Board &board) {
    // blank tile not in first row
    return positionOfTile(0, board) >= 4;
}

bool BFS::canMoveDown(const Board &board) {
    // blank tile not in last row
    return positionOfTile(0, board) <= 15;
}

bool BFS::canMoveLeft(const Board &board) {
    // blank tile not in left column
    return positionOfTile(0, board) % 4;
}

bool BFS::canMoveRight(const Board &board) {
    // blank tile not in right column
    return (positionOfTile(0, board) % 4) != 3;
}

/*
 * Move tile functions
 */

void BFS::moveTile(int pos0, int pos1, Board &board) {
    int hold = board.state[pos0];
    board.state[pos0] = board.state[pos1];
    board.state[pos1] = hold;
}

void BFS::moveUp(Board &board) {
    moveTile(positionOfTile(0, board), positionOfTile(0, board) - 4, board);
}

void BFS::moveDown(Board &board) {
    moveTile(positionOfTile(0, board), positionOfTile(0, board) + 4, board);
}

void BFS::moveLeft(Board &board) {
    moveTile(positionOfTile(0, board), positionOfTile(0, board) - 1, board);
}

void BFS::moveRight(Board &board) {
    moveTile(positionOfTile(0, board), positionOfTile(0, board) + 1, board);
}


/*
 * BFS functions
 */

void BFS::BreadthFirstSearch(Board *board) {
    // add starting board to open list, set initial function values, and increment total adds
    openList.push_back(board);
    setFunctionValues(board);
    openListTotalAdds++;

    // do while goal state hasn't been found
    while (!goalFound) {
        // terminate search after 50,000 states have been explored and no solution has been found
        if (closedListTotalAdds >= 50000) {
            cout << "Terminating Search" << endl;
            cout << "After 50,000 explored states, no goal state was found" << endl;
            return;
        }

        // check if board is goal state
        if (openList.front()->isGoalState()) {
            // goal state found
            goalFound = true;

            // create string of boards that found the solution
            CreateBoardTrail(openList.front());
            PrintBoardTrail();
        } else {
            // add first board in the queue to the closed list and increment total adds
            closedList.push_back(openList.front());
            closedListTotalAdds++;

            // expand the first board in the queue
            CreateChildren(openList.front());

            // pop the first board in the queue
            openList.pop_front();
        }
    }
}

void BFS::CreateChildren(Board *board) {
    // check all four directions and create children boards
    for (int i = 0; i < 4; ++i) {
        if ((this->*canMove[i])(*board)) {

            // create child for tile change
            if (board->child[i] == nullptr) {

                // create the child (copy of parent)
                board->child[i] = new Board(*board);

                // move the tile
                (this->*moveBoard[i])(*board->child[i]);

                // set the parent
                board->child[i]->parent = board;

                // set function values
                setFunctionValues(board->child[i]);

                // check if child is in closed list
                if (isBoardInClosedList(board->child[i])) {
                    // delete child if already exists in closed list
                    delete board->child[i];
                    board->child[i] = nullptr;
                } else {
                    // add child board to open list and increment total adds
                    openList.push_back(board->child[i]);
                    openListTotalAdds++;
                }
            }
        }
    }
}

void BFS::setFunctionValues(Board *board) {
    board->g_of_n = 1;
    board->h_of_n = 0;
    board->f_of_n = 1;
    board->priorityValue = 1;
}

void BFS::CreateBoardTrail(Board *board) {
    Board* boardPtr = board;
    while (boardPtr) {
        trailOfBoards.insert(trailOfBoards.begin(), boardPtr);
        boardPtr = boardPtr->parent;
    }
}

void BFS::PrintBoardTrail() {
    cout << "~*~*~ GOAL STATE FOUND ~*~*~" << endl << endl;
    cout << "-- Length of path: " << trailOfBoards.size() << endl;
    cout << "-- Number of boards added to Open List: " << openListTotalAdds << endl;
    cout << "-- Number of boards added to Closed List: " << closedListTotalAdds << endl << endl;

    for (auto & board : trailOfBoards) {
        board->printStateFancy();
    }
}
