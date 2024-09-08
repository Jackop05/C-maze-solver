# Maze Solver Program

## Overview
This C program is a **high-performance maze solver** designed to solve mazes quickly and with minimal RAM usage. It utilizes an efficient Breadth-First Search (BFS) algorithm to find the shortest path from the start position (denoted as 'P') to the end position (denoted as 'K') in a maze file.

The program reads a maze from a file, finds the positions of the start ('P') and end ('K') points, and computes the shortest path between them. The steps taken to solve the maze are printed to the console, along with the total number of steps.

## Features
- **Fast execution**: The BFS algorithm is optimized for quick performance.
- **Minimal memory usage**: The program uses temporary files to store the path, reducing memory footprint.
- **Console output**: The program prints the maze dimensions, the positions of the start and end points, and the number of steps in the solution.
- **Error handling**: The program checks for input file validity and other runtime errors.

## Files
- **`mazeSolver.c`**: The main program that reads the maze file, initializes variables, and runs the maze-solving algorithm.
- **`mazeSolver.h`**: Header file containing the BFS algorithm and other function declarations.
- **`printMovesToConsole.h`**: Header file containing functions for printing the moves to the console.

## Compilation

To compile the program, run the following command in your terminal:

```bash
gcc -o mazeSolver main.c printMove.c solveMaze.c
