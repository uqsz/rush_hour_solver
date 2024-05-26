#ifndef RUSH_HOUR_SOLVER_STATE_H
#define RUSH_HOUR_SOLVER_STATE_H


#include "../util/utils.h"
#include "../car/car.h"

#include <iostream>
#include <vector>

class State {
private:
    std::vector<Car> cars;
    std::vector<bool> hash;
    int deanID;
    moveInfo stateMove;

public:
    static int rows;
    static int cols;

    State();

    State(std::vector<Car> c, std::vector<bool> h, int id, moveInfo s);

    inline bool getHash(int i) const;

    inline std::vector<Car> getCars() const { return cars; }

    inline std::vector<bool> getHashes() const { return hash; }

    inline int getDeanID() const { return deanID; }

    inline moveInfo getStateMove() const { return stateMove; }

    inline void setHash(int i) { hash.at(i) = true; }

    inline void updateMoveInfo() { stateMove.n += 2; }

    void addCar(Car &car);

    void addDean(Car &car);

    void updateHash(Car &car);

    void show_bools();

    void show_cars();

    void show();

    bool operator<(const State &other) const;

    bool operator==(const State &other) const;

    bool operator!=(const State &other) const;

    int howManyUp(int row, int col) const;

    int howManyDown(int row, int col, int len) const;

    int howManyRight(int row, int col, int len) const;

    int howManyLeft(int row, int col) const;

    void moveVertical(int id, int n);

    void moveHorizontal(int id, int n);

    bool isGameWon();
};



#endif //RUSH_HOUR_SOLVER_STATE_H
