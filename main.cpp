//
// Created by Coleman on 9/16/2019.
//

#include <iostream>
#include <conio.h>
#include "Board.h"
#include "BFS.h"
#include "A_Star.h"

using namespace std;

int main() {
    cout << "----------------------" << endl
         << "--- 19-Tile Puzzle ---" << endl
         << "----------------------" << endl << endl;

    int userStartArray[20];
    int userGoalArray[20];

    // get the user input start state
    while (true) {
        cout << "Input start state..." << endl;
        for (int i = 0; i < 20; ++i) {
            cout << "Index " << i << ": ";
            cin >> userStartArray[i];
        }

        char correct;
        cout << endl << "[";
        for (int i = 0; i < 19; ++i) {
            cout << userStartArray[i] << ", ";
        }
        cout << userStartArray[19] << "]";
        cout << endl << "Is this correct? (Y/n): ";
        cin >> correct;

        if (!( correct != 'Y' && correct != 'y' )) {
            break;
        }
    }

    // get the user input goal state
    while (true) {
        cout << endl << endl << "Input goal state..." << endl;
        for (int i = 0; i < 20; ++i) {
            cout << "Index " << i << ": ";
            cin >> userGoalArray[i];
        }

        char correct;
        cout << endl << "[";
        for (int i = 0; i < 19; ++i) {
            cout << userGoalArray[i] << ", ";
        }
        cout << userGoalArray[19] << "]";
        cout << endl << "Is this correct? (Y/n): ";
        cin >> correct;

        if (!( correct != 'Y' && correct != 'y' )) {
            break;
        }
    }

    // Create starting boards
    Board BFS_Board(userStartArray, userGoalArray);
    Board A_Star_1_Board(userStartArray, userGoalArray);
    Board A_Star_2_Board(userStartArray, userGoalArray);

    // Breadth First Search
    cout << endl << endl;
    cout << "-----------" << endl
         << "--- BFS ---" << endl
         << "-----------" << endl << endl;
    BFS bfs;
    bfs.breadthFirstSearch(&BFS_Board);

    // A* Search with Heuristic 1
    cout << endl;
    cout << "---------------------------" << endl
         << "--- A* with Heuristic 1 ---" << endl
         << "---------------------------" << endl << endl;
    A_Star as1(1);
    as1.aStarSearch(&A_Star_1_Board);

    // A* Search with Heuristic 1
    cout << endl;
    cout << "---------------------------" << endl
         << "--- A* with Heuristic 2 ---" << endl
         << "---------------------------" << endl << endl;
    A_Star as2(2);
    as2.aStarSearch(&A_Star_2_Board);

    getch();
    return 0;
}
