//
// Created by Coleman on 9/23/2019.
//

#include <vector>
#include <iostream>

#include "A_Star_1.h"

using namespace std;

// static ints
int A_Star_1::openListTotalAdds = 0;
int A_Star_1::closedListTotalAdds = 0;

/*
 * Constructor
 */
A_Star_1::A_Star_1(int heuristic)
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
    canMove[0] = &A_Star_1::canMoveUp;
    canMove[1] = &A_Star_1::canMoveDown;
    canMove[2] = &A_Star_1::canMoveLeft;
    canMove[3] = &A_Star_1::canMoveRight;

    // Pointers to move functions
    moveBoard[0] = &A_Star_1::moveUp;
    moveBoard[1] = &A_Star_1::moveDown;
    moveBoard[2] = &A_Star_1::moveLeft;
    moveBoard[3] = &A_Star_1::moveRight;

    // Set pointer to correct heuristic function
    if (heuristic == 1) {
        heuristicFn = &A_Star_1::getHeuristicScore1;
    } else {
        heuristicFn = &A_Star_1::getHeuristicScore2;
    }
}


/*
 * General Functions
 */
int A_Star_1::positionOfTile(int num, const Board &board) {
    for (int i = 0; i < 20; ++i) {
        if (board.state[i] == num) {
            return i;
        }
    }
    return -1;
}

bool A_Star_1::isBoardInClosedList(Board *board) {
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
bool A_Star_1::canMoveUp(const Board &board) {
    // blank tile not in first row
    return positionOfTile(0, board) >= 4;
}

bool A_Star_1::canMoveDown(const Board &board) {
    // blank tile not in last row
    return positionOfTile(0, board) <= 15;
}

bool A_Star_1::canMoveLeft(const Board &board) {
    // blank tile not in left column
    return positionOfTile(0, board) % 4;
}

bool A_Star_1::canMoveRight(const Board &board) {
    // blank tile not in right column
    return (positionOfTile(0, board) % 4) != 3;
}


/*
 * Move tile functions
 */
int A_Star_1::moveTile(int pos0, int pos1, Board &board) {
    // pos0 = index of 0 (blank)
    // pos1 = index of tile
    int tileNumber = board.state[pos1];
    board.state[pos0] = board.state[pos1];
    board.state[pos1] = 0;
    return tileNumber;
}

int A_Star_1::moveUp(Board &board) {
    return moveTile(positionOfTile(0, board), positionOfTile(0, board) - 4, board);
}

int A_Star_1::moveDown(Board &board) {
    return moveTile(positionOfTile(0, board), positionOfTile(0, board) + 4, board);
}

int A_Star_1::moveLeft(Board &board) {
    return moveTile(positionOfTile(0, board), positionOfTile(0, board) - 1, board);
}

int A_Star_1::moveRight(Board &board) {
    return moveTile(positionOfTile(0, board), positionOfTile(0, board) + 1, board);
}


/*
 * A* Functions
 */
void A_Star_1::aStarSearch(Board *board) {
    // add starting board to open list, set initial function values, and increment total adds
    openList.push_back(board);
    setFunctionValues(board);
    openListTotalAdds++;

    // do while a goal state hasn't been found
    while (!goalFound) {
        // terminate search after 50,000 states have been explored and no solution has been found
        if (closedListTotalAdds >= 50000) {
            cout << "Terminating Search" << endl;
            cout << "After 50,000 explored states, no goal state was found" << endl << endl;
            return;
        }

        // make pointer to first node in queue and then pop it out of the queue
        Board* currBoard = openList.front();
        openList.pop_front();

        // check if board is goal state
        if (currBoard->isGoalState()) {
            // goal state found
            goalFound = true;

            // create string of boards that found the solution
            createBoardTrail(currBoard);
            printBoardTrail();
        } else {
            // add first board in the queue to the closed list and increment total adds
            closedList.push_back(currBoard);
            closedListTotalAdds++;

            // expand the first board in the queue
            createChildren(currBoard);
        }
    }
}

void A_Star_1::createChildren(Board *board) {
    // check all four directions and create children boards
    for (int i = 0; i < 4; ++i) {
        if ((this->*canMove[i])(*board)) {

            // create child for tile change
            if (board->child[i] == nullptr) {

                // create the child (copy of parent)
                board->child[i] = new Board(*board);

                // move the tile and record the tile number that moved
                int tileMoved = (this->*moveBoard[i])(*board->child[i]);

                // set the parent
                board->child[i]->parent = board;

                // set function values
                setFunctionValues(board->child[i], tileMoved);

                // check if child is in closed list
                if (isBoardInClosedList(board->child[i])) {
                    // delete child if already exists in closed list
                    delete board->child[i];
                    board->child[i] = nullptr;
                } else {
                    // add child board to open list and increment total adds
                    insertBoardToPriorityQueue(board->child[i]);
                    openListTotalAdds++;
                }
            }
        }
    }
}

void A_Star_1::setFunctionValues(Board *board, int tileNumber) {
    // set g_of_n (the cost of making a move) equal to 1 if tile# is 1-9 or 2 if tile# is 10-19
    if (tileNumber >= 10) {
        board->g_of_n = board->parent->g_of_n + 2;
    } else if (tileNumber >= 1) {
        board->g_of_n = board->parent->g_of_n + 1;
    } else {
        board->g_of_n = 0;
    }

    // set h_of_n (heuristic score)
    board->h_of_n = (this->*heuristicFn)(*board);

    // set f_of_n (path cost + heuristic score)
    board->f_of_n = board->g_of_n + board->h_of_n;

    // set priority value
    board->priorityValue = 1;
}

int A_Star_1::getHeuristicScore1(Board &board) {
    // Estimated cost of taking this board B to the goal state G is equal to the number of tiles in B
    // that are not in the correct location as required by G
    int score = 20;
    for (int i = 0; i < 20; ++i) {
        if (board.state[i] == board.goalState[i]) {
            score--;
        }
    }
    return score;
}

int A_Star_1::getHeuristicScore2(Board &board) {
    // Estimated cost of taking this board B to the goal state G is the sum of the smallest number of
    // moves for each tile (that is not already at its final location) to reach its final location as
    // required by G
    int score = 0;
    for (int i = 0; i < 20; ++i) {
        if (board.state[i] != board.goalState[i]) {
            // if tile is not in it's correct location, then calculate number of moves
            score += getRowDifference(board.state[i], board) + getColumnDifference(board.state[i], board);
        }
    }

    return score;
}

int A_Star_1::getRowDifference(int tile, Board &board) {
    int pos1 = 0;  // position of current state tile
    int pos2 = 0;  // position of goal state tile
    for (int i = 0; i < 20; ++i) {
        if (tile == board.state[i]) {
            pos1 = i;
        }
        if (tile == board.goalState[i]) {
            pos2 = i;
        }
    }

    return abs((pos1 / 4) - (pos2 / 4));
}

int A_Star_1::getColumnDifference(int tile, Board &board) {
    int pos1 = 0;  // position of current state tile
    int pos2 = 0;  // position of goal state tile
    for (int i = 0; i < 20; ++i) {
        if (tile == board.state[i]) {
            pos1 = i;
        }
        if (tile == board.goalState[i]) {
            pos2 = i;
        }
    }

    return abs((pos1 % 4) - (pos2 % 4));
}

void A_Star_1::insertBoardToPriorityQueue(Board *board) {
    list<Board*>::iterator boardInList;

    // check if state already exists in open list
    for (boardInList = openList.begin(); boardInList != openList.end(); boardInList++) {
        if ((**boardInList) == (*board) && (*board).f_of_n < (**boardInList).f_of_n) {
            // replace the board in the open list with the new board that has a lower score, and end insertion function
            (*boardInList) = board;
            return;
        } else if ((**boardInList) == (*board)) {
            // add board to closed list, increment closed list count, and end insertion function
            closedList.push_back(board);
            closedListTotalAdds++;
            return;
        }
    }

    // insert board into list based on f_of_n
    bool wasInserted = false;
    for (boardInList = openList.begin(); boardInList != openList.end(); boardInList++) {
        if ((*board).f_of_n < (**boardInList).f_of_n) {
            openList.insert(boardInList, board);
            wasInserted = true;
            break;
        }
    }

    // if board was not inserted, add to end of open list
    if (!wasInserted) {
        openList.push_back(board);
    }
}

void A_Star_1::createBoardTrail(Board *board) {
    Board* boardPtr = board;
    while (boardPtr) {
        trailOfBoards.insert(trailOfBoards.begin(), boardPtr);
        boardPtr = boardPtr->parent;
    }
}

void A_Star_1::printBoardTrail() {
    cout << "--- GOAL STATE FOUND ---" << endl << endl;

    // Get search statistics
    int tileMovementCost;
    for (auto & board : trailOfBoards) {
        tileMovementCost = board->g_of_n;
    }

    // Print search statistics
    cout << "--- Search Statistics ---" << endl;
    cout << "Length of path: " << trailOfBoards.size() << endl;
    cout << "Number of boards added to Open List: " << openListTotalAdds << endl;
    cout << "Number of boards added to Closed List: " << closedListTotalAdds << endl;
    cout << "Total movement cost: " << tileMovementCost << endl << endl;

    // Print Boards from Start -> Goal
    cout << "--- Sequence of Boards ---" << endl;
    for (auto & board : trailOfBoards) {
        board->printStateFancy();
    }
}
