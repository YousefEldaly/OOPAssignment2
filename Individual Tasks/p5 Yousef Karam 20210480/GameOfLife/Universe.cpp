//
// Created by Youssef on 11/10/2022.
//

#include "Universe.h"
#include <iostream>

using namespace std;

void Universe::initialize() {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            universe[i][j] = rand() % 2;
        }
    }
}

void Universe::display() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (universe[i][j] == 1) {
                cout << "O";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
    for(int i = 0 ; i < column ; i++){
        cout << "-";
    }
    cout << endl;
}

void Universe::reset() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            universe[i][j] = 0;
        }
    }
}

int Universe::count_neighbours(int universe[border_row][border_column], int row, int column) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (universe[row + i][column + j] == 1) {
                count++;
            }
        }
    }
    return count;
}

void Universe::next_generation() {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            int neighbours = count_neighbours(universe, i, j);
            if (universe[i][j] == 1) {
                if (neighbours < 2) {
                    universe[i][j] = 0;
                } else if (neighbours == 2 || neighbours == 3) {
                    universe[i][j] = 1;
                } else if (neighbours > 3) {
                    universe[i][j] = 0;
                }
            } else {
                if (neighbours == 3) {
                    universe[i][j] = 1;
                }
            }
        }
    }
}

void Universe::run(int n) {
    int turn = 0;
    initialize();
    display();
    for (int i = 0; (i) < n; i++) {
        next_generation();
        display();
        turn++;
        for(int i = 0 ; i < column ; i++){
            cout << "-";
        }
        cout << endl;
    }
    reset();
    display();
}