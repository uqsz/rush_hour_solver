#include "state.h"

State::State() {
    {
        hash.assign(rows * cols, false);
    }
}

State::State(std::vector<Car> c, std::vector<bool> h, int id, moveInfo s)
        : cars(c), hash(h), deanID(id), stateMove(s) {
}

bool State::getHash(int i) const {
    if (i < rows * cols)
        return hash[i];
    return false;
}

void State::addCar(Car &car) {
    cars.push_back(car);
    updateHash(car);
    // show();
}

void State::addDean(Car &car) {
    deanID = cars.size();
    cars.push_back(car);
    updateHash(car);
}

void State::updateHash(Car &car) {
    switch (car.getDir()) {
        case (VERTICAL): {
            for (int i = 0; i < car.getLen(); i++) {
                hash.at((i + car.getRow()) * cols + car.getCol()) = true;
            }
            break;
        }
        case (HORIZONTAL): {
            for (int j = 0; j < car.getLen(); j++) {
                hash.at((car.getRow()) * cols + car.getCol() + j) = true;
            }
            break;
        }
    }
}
void State::show_bools() {
    for (int i = 0; i < rows * cols; i++) {
        std::cout << hash[i];
        if ((i) % cols == cols - 1)
            std::cout << std::endl;
    }
}

void State::show_cars() {
    for (auto &car: cars) {
        std::cout << car << std::endl;
    }
}

void State::show() {
    show_bools();
    show_cars();
}

bool State::operator<(const State &other) const {
    for (int i = 0; i < rows * cols; i++)
        if (hash[i] != other.getHash(i))
            return hash[i] < other.getHash(i);
    return false;
}

bool State::operator==(const State &other) const {
    for (int i = 0; i < rows * cols; i++)
        if (hash[i] != other.getHash(i))
            return false;
    return true;
}

bool State::operator!=(const State &other) const {
    for (int i = 0; i < rows * cols; i++)
        if (hash[i] != other.getHash(i))
            return true;
    return false;
}

int State::howManyUp(int row, int col) const {
    int cnt = 0;
    while (row - cnt > 0 && !hash.at((row - cnt - 1) * cols + col))
        cnt++;
    return cnt;
}

int State::howManyDown(int row, int col, int len) const {
    int cnt = 0;
    while (row + len + cnt < rows - 1 && !hash.at((row + len + cnt) * cols + col))
        cnt++;
    return cnt;
}

int State::howManyRight(int row, int col, int len) const {
    int cnt = 0;
    while (col + len + cnt < cols  && !hash.at((row) * cols + col + len + cnt))
        cnt++;
    return cnt;
}

int State::howManyLeft(int row, int col) const {
    int cnt = 0;
    while (col - cnt > 0 && !hash.at(row * cols + col - cnt - 1))
        cnt++;
    return cnt;
}

void State::moveVertical(int id, int n) {
    Car &c = cars.at(id);
    for (int cnt = 0; cnt < c.getLen(); cnt++) {
        hash.at((c.getRow() + cnt) * cols + c.getCol()) = false;
    }
    for (int cnt = 0; cnt < c.getLen(); cnt++) {
        hash.at((c.getRow() + cnt + n) * cols + c.getCol()) = true;
    }
    c.updateRow(n);
}

void State::moveHorizontal(int id, int n) {
    Car &c = cars.at(id);
    for (int cnt = 0; cnt < c.getLen(); cnt++) {
        hash.at(c.getRow() * cols + c.getCol() + cnt) = false;
    }
    for (int cnt = 0; cnt < c.getLen(); cnt++) {
        hash.at(c.getRow() * cols + c.getCol() + cnt + n) = true;
    }
    c.updateCol(n);
}

bool State::isGameWon() {
    Car c = cars.at(deanID);
    switch (c.getDir()) {
        case (VERTICAL): {
            return c.getRow() == 0 || (c.getRow() + c.getLen()) == rows;
        }
        case (HORIZONTAL): {
            return c.getCol()==0 || (c.getCol() + c.getLen()) == cols;

        }
    }
    return false;
}

