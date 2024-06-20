# Rush Hour Solver

## What is a game about?

Rush Hour is a sliding block puzzle game that challenges players to navigate a gridlocked parking lot by moving vehicles out of the way to clear a path for a specific target car to exit the grid. 

![test](https://3.bp.blogspot.com/-43gX1ZUjfAU/UDe0_yuyXsI/AAAAAAAAAgY/3FYnJmK160Y/s200/trafficjam.png)

## How solver works?

### Input
The input consists of a single line containing in turn the numbers W, H, and N, followed by a sequence of H lines, where each contains W characters describing successive fields of the board, with the following meaning:

1. "." - an empty field,
2. "#" - a blocked field,
3. "a" - the beginning of a horizontally oriented car, the next field to the right contains the symbol
"b", further fields may contain "c" and further "d" (cars of length 2 end in "b", cars of
length 3 end with "c", and those with length 4 end with "d").
1
4. "x" - the beginning of a vertically oriented car, the next field down from that contains the symbol
"y", further fields may contain "z" and further "w" (cars of length 2 end in "y", cars of
length 3 end with "z", and those with length 4 end with "w").
5. "o" - the field occupied by the main car (the main car consists of 2 to 4
"o" symbols arranged vertically or horizontally in succession, according to its orientation, on the board there is only one main car).

Input examples are available in [test inputs](tests/tests_input/).

### Main algorithm

Solver uses BFS by exploring all possible moves in a systematic manner, ensuring the shortest path to the solution is found.The algorithm involves initializing a queue with the initial state of the board, representing each state as a snapshot of the board configuration, and processing the queue by generating and enqueuing all valid new states while keeping track of visited states to avoid redundancy.

## Summary

This solver provides an efficient method to tackle the Rush Hour puzzle using BFS, ensuring that the shortest solution path is identified by exploring all possible moves in a systematic manner. It serves as a practical example of applying graph search algorithms to solve real-world puzzles.
