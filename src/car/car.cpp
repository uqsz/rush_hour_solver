#include "car.h"

Car::Car(int r, int c, int l, Direction d)
        : row(r), col(c), len(l), dir(d) {
}

std::ostream& operator<<(std::ostream& os, const Car& c)
{
    os << "R/C:" << c.row << "/" << c.col;
    os << " L:" << c.len;
    os << " D:" << c.dir;
    return os;
}
