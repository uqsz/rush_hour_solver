#ifndef RUSH_HOUR_SOLVER_UTILS_H
#define RUSH_HOUR_SOLVER_UTILS_H


#include <iostream>
#include <vector>

struct moveInfo {
    int col;
    int row;
    char dir;
    int n;
};

enum Direction {
    VERTICAL,
    HORIZONTAL
};


#endif //RUSH_HOUR_SOLVER_UTILS_H
