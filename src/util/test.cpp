
#include <string>
#include <fstream>
#include "../state/state.h"

State load_file(std::string filepath);

std::string BFS(State &initialState);

void test() {
    for (int i = 0; i < 11; i++) {
        std::string input_file_path = std::string(TEST_INPUT_DIR) + "/test" + std::to_string(i) + ".txt";

        std::string output_file_path = std::string(TEST_OUTPUT_DIR) + "/test" + std::to_string(i) + "out.txt";

        State initialState = load_file(input_file_path);

        std::string s = BFS(initialState);

        std::ofstream out_file(output_file_path);
        if (out_file.is_open()) {
            out_file << s;
            out_file.close();
        } else {
            std::cerr << "Failed to open file for writing: " << output_file_path << std::endl;
        }
    }
}