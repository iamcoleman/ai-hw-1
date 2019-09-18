//
// Created by Coleman on 9/17/2019.
//

#include <queue>
#include <vector>
#include <iostream>

#include "BFS.h"

using namespace std;

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

bool BFS::isBoardInClosedList(Board &board) {
    for (vector<Board>::size_type i = 0; i != closedList.size(); i++) {
        if (closedList[i] == board) {
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

void BFS::BreadthFirstSearch(Board &board) {
    // add starting board to open list
    openList.push_back(board);

    // do while goal state hasn't been found
    while (!goalFound) {
        // testing - print state
        //openList.front().printStateFancy();

        // check if board is goal state
        if (openList.front().isGoalState()) {
            // goal state
            goalFound = true;
            cout << endl << "Goal State Found!" << endl;
            openList.front().printStateFancy();
            // create string of parents
        } else {
            // add first board in the queue to the closed list
            closedList.push_back(board);

            // expand the first board in the queue
            CreateChildren(openList.front());

            // pop the first board in the queue
            openList.pop_front();
        }
    }
}

void BFS::CreateChildren(Board &board) {
    // check all four directions and create children boards
    for (int i = 0; i < 4; ++i) {
        if ((this->*canMove[i])(board)) {

            // create child for tile change
            if (board.child[i] == nullptr) {

                // create the child (copy of parent)
                board.child[i] = new Board(board);

                // move the tile
                (this->*moveBoard[i])(*board.child[i]);

                // set the parent
                board.child[i]->parent = &board;

                // check if child is in closed list
                if (isBoardInClosedList(*board.child[i])) {
                    // delete child
                    delete board.child[i];
                    board.child[i] = nullptr;
                } else {
                    // add child board to open list
                    openList.push_back(*board.child[i]);
                }
            }
        }
    }
}
