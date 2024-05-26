#include "../state/state.h"
#include "utils.h"
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>

using std::vector;
using std::string;

void parse(int rows, int columns, vector<string> board, State &initialState) {
    char t;
    int len;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {

            t = board[i][j];
            if (t == 'a') {
                len = 2;
                if (j + 2 < columns && board[i][j + 2] == 'c') {
                    len += 1;
                    if (j + 3 < columns && board[i][j + 3] == 'd') {
                        len += 1;
                    }
                }
                Car car(i, j, len, HORIZONTAL);
                initialState.addCar(car);

            } else if (t == 'x') {
                len = 2;
                if (i + 2 < rows && board[i + 2][j] == 'z') {
                    len += 1;
                    if (i + 3 < rows && board[i + 3][j] == 'w') {
                        len += 1;
                    }
                }

                Car car(i, j, len, VERTICAL);
                initialState.addCar(car);
            } else if (t == 'o') {
                len = 2;
                int cnt = 2;
                Direction dir;
                board[i][j] = '0';
                if (j + 1 < columns && board[i][j + 1] == 'o') {
                    board[i][j + 1] = '0';
                    while (j + cnt < columns && board[i][j + cnt] == 'o') {
                        board[i][j + cnt] = '0';
                        len += 1;
                        cnt++;
                    }
                    dir = HORIZONTAL;
                }
                if (i + 1 < rows && board[i + 1][j] == 'o') {
                    board[i + 1][j] = '0';
                    while (i + cnt < rows && board[i + cnt][j] == 'o') {
                        board[i + cnt][j] = '0';
                        len += 1;
                        cnt++;
                    }
                    dir = VERTICAL;
                }
                Car car(i, j, len, dir);
                initialState.addDean(car);
            } else if (t == '#') {
                initialState.setHash(i * columns + j);
            }
        }
    }
}


State load_file(string filepath) {
    std::string input;
    std::ifstream file(filepath);

    if (file.is_open()) {
        input.assign((std::istreambuf_iterator<char>(file)),
                     (std::istreambuf_iterator<char>()));
        file.close();
    } else {
        std::cerr << filepath << std::endl << strerror(errno) << std::endl;
    }

    vector<string> x;
    string line;
    std::istringstream iss(input);

    int rows, cols, steps;
    iss >> cols >> rows >> steps;

    State::rows = rows;
    State::cols = cols;

    while (std::getline(iss, line)) {
        if (!line.empty()) {
//            std::cout << line << std::endl;
            x.push_back(line);
        }
    }

    State initialState;

    parse(rows, cols, x, initialState);
    return initialState;

}