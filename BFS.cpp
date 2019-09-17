//
// Created by Coleman on 9/17/2019.
//

#include <queue>
#include <vector>

#include "BFS.h"

using namespace std;

int BFS::positionOfTile(int num, const Board &board) {
    for (int i = 0; i < 20; ++i) {
        if (board.state[i] == num) {
            return i;
        }
    }
    return -1;
}

bool BFS::canMoveUp(const Board &board) {
    return positionOfTile(0, board) >= 4;
}

bool BFS::canMoveDown(const Board &board) {
    return positionOfTile(0, board) <= 15;
}

bool BFS::canMoveLeft(const Board &board) {
    return positionOfTile(0, board) % 4;
}

bool BFS::canMoveRight(const Board &board) {
    return (positionOfTile(0, board) % 4) != 3;
}

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


