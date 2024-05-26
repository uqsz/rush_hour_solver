#ifndef RUSH_HOUR_SOLVER_CAR_H
#define RUSH_HOUR_SOLVER_CAR_H

#include <iostream>
#include "../util/utils.h"

class Car {
private:
    int row;
    int col;
    int len;
    Direction dir;

public:
    Car(int r, int c, int l, Direction d);

    inline int getRow() const { return row; }

    inline int getCol() const { return col; }

    inline int getLen() const { return len; }

    inline Direction getDir() const { return dir; }

    inline void updateRow(int n) { row += n; }

    inline void updateCol(int n) { col += n; }

    friend std::ostream &operator<<(std::ostream &os, const Car &c);

};


#endif //RUSH_HOUR_SOLVER_CAR_H
