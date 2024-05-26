cmake_minimum_required(VERSION 3.24)
project(rush_hour_solver)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DTEST_INPUT_DIR=\"${CMAKE_SOURCE_DIR}/tests/tests_input\")
add_definitions(-DTEST_OUTPUT_DIR=\"${CMAKE_SOURCE_DIR}/tests/tests_output\")

add_executable(rush_hour_solver src/main.cpp src/car/car.cpp src/car/car.h src/state/state.cpp src/state/state.h src/util/utils.h src/util/parser.cpp src/util/bfs.cpp src/util/test.cpp)
