#include <map>
#include <queue>
#include "../state/state.h"

using std::vector;
using std::string;

vector<State> genNextStates(State &initialState) {
    vector<State> newStates;
    int howManyMoves, cnt;
    for (int id = 0; id < initialState.getCars().size(); id++) {
        Car c = initialState.getCars().at(id);
        switch (c.getDir()) {
            case (VERTICAL): {

                howManyMoves = initialState.howManyUp(c.getRow(), c.getCol());
                for (cnt = 1; cnt <= howManyMoves; cnt++) {
                    State nextState(initialState.getCars(), initialState.getHashes(), initialState.getDeanID(),
                                    moveInfo{c.getCol(), c.getRow(), 'U', cnt});
                    nextState.moveVertical(id, -cnt);
                    newStates.push_back(nextState);
                }

                howManyMoves = initialState.howManyDown(c.getRow(), c.getCol(), c.getLen());
                for (cnt = 1; cnt <= howManyMoves; cnt++) {
                    State nextState(initialState.getCars(), initialState.getHashes(), initialState.getDeanID(),
                                    moveInfo{c.getCol(), c.getRow(), 'D', cnt});
                    nextState.moveVertical(id, cnt);
                    newStates.push_back(nextState);
                }
                break;
            }
            case (HORIZONTAL): {
                howManyMoves = initialState.howManyLeft(c.getRow(), c.getCol());
                for (cnt = 1; cnt <= howManyMoves; cnt++) {
                    State nextState(initialState.getCars(), initialState.getHashes(), initialState.getDeanID(),
                                    moveInfo{c.getCol(), c.getRow(), 'L', cnt});
                    nextState.moveHorizontal(id, -cnt);
                    newStates.push_back(nextState);
                }
                howManyMoves = initialState.howManyRight(c.getRow(), c.getCol(), c.getLen());
                for (cnt = 1; cnt <= howManyMoves; cnt++) {
                    State nextState(initialState.getCars(), initialState.getHashes(), initialState.getDeanID(),
                                    moveInfo{c.getCol(), c.getRow(), 'R', cnt});
                    nextState.moveHorizontal(id, cnt);
                    newStates.push_back(nextState);
                }
                break;
            }
        }
    }
    return newStates;
}

bool stateVisited(const State &state, const std::map<State, State> &visitedStates) {
    return visitedStates.find(state) != visitedStates.end();
}

string BFS(State &initialState) {
    std::queue<State> queue;
    std::map<State, State> stateToParent;
    queue.push(initialState);
    stateToParent[initialState] = initialState;

    while (!queue.empty()) {
        State current = queue.front();
        queue.pop();

        vector<State> nextStates = genNextStates(current);

        for (auto &nextState: nextStates) {
            if (!stateVisited(nextState, stateToParent)) {
                queue.push(nextState);
                stateToParent[nextState] = current;
                if (nextState.isGameWon()) {
                    nextState.updateMoveInfo();
                    vector<moveInfo> moves;
                    while (stateToParent.at(nextState) != nextState) {
                        moves.push_back(nextState.getStateMove());
                        nextState = stateToParent.at(nextState);
                    }
                    string s;
                    s += std::to_string(moves.size()) + "\n";
                    for (int i = moves.size() - 1; i > -1; i--) {
                        moveInfo move = moves.at(i);
                        s += std::to_string(move.col) + " " + std::to_string(move.row) + " " + move.dir + " " +
                             std::to_string(move.n) + "\n";
                    }
//                    std::cout << s;
                    return s;
                }
            }
        }
    }
}