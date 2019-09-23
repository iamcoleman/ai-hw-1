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
A_Star_1::A_Star_1()
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
void A_Star_1::moveTile(int pos0, int pos1, Board &board) {
    int hold = board.state[pos0];
    board.state[pos0] = board.state[pos1];
    board.state[pos1] = hold;
}

void A_Star_1::moveUp(Board &board) {
    moveTile(positionOfTile(0, board), positionOfTile(0, board) - 4, board);
}

void A_Star_1::moveDown(Board &board) {
    moveTile(positionOfTile(0, board), positionOfTile(0, board) + 4, board);
}

void A_Star_1::moveLeft(Board &board) {
    moveTile(positionOfTile(0, board), positionOfTile(0, board) - 1, board);
}

void A_Star_1::moveRight(Board &board) {
    moveTile(positionOfTile(0, board), positionOfTile(0, board) + 1, board);
}


