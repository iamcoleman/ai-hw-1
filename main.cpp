//
// Created by Coleman on 9/16/2019.
//

#include <iostream>
#include "Board.h"
#include "BFS.h"
#include "A_Star_1.h"

using namespace std;

int main() {
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~" << endl << "~~~ 19-Tile Puzzle ~~~" << endl << "~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

    int startArray[20] = { 9, 16, 19, 0, 2, 6, 1, 17, 12, 15, 14, 7, 11, 10, 13, 18, 8, 5, 4, 3 };
    int startArray2[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 0, 17, 18, 19 };
    int startArray3[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0, 15, 16, 17, 18, 19 };
    int startArray4[20] = { 0, 2, 3, 4, 1, 6, 7, 8, 5, 10, 11, 12, 9, 14, 15, 16, 13, 17, 18, 19 };

    int goalArray[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0 };

    Board testBoard(startArray4, goalArray);

    // Breadth First Search
//    BFS bfs;
//    bfs.breadthFirstSearch(&testBoard);

    // A* Search with Heuristic 1
    A_Star_1 as1;
    as1.aStarSearch(&testBoard);

    return 0;
}
