//
// Created by Youssef on 11/10/2022.
//

#ifndef GAMEOFLIFE_UNIVERSE_H
#define GAMEOFLIFE_UNIVERSE_H


class Universe {
private:
    int row = 10;
    const static int border_row = 15;
    int column = 20;
    const static int border_column = 25;
    int universe[border_row][border_column];
public:
    void initialize();
    void reset();
    int count_neighbours(int universe[border_row][border_column], int row, int column);
    void next_generation();
    void display();
    void run(int n);
};


#endif //GAMEOFLIFE_UNIVERSE_H
