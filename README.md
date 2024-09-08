# 🔢 Maze Solver Program

## 📝 Overview
This C program is a **high-performance maze solver** designed to solve mazes quickly and with minimal RAM usage. It utilizes an efficient Breadth-First Search (BFS) algorithm to find the shortest path from the start position (denoted as 'P') to the end position (denoted as 'K') in a maze file.

The program reads a maze from a file, finds the positions of the start ('P') and end ('K') points, and computes the shortest path between them. The steps taken to solve the maze are printed to the console, along with the total number of steps.

## 💡 Features
- **Fast execution**: The BFS algorithm is optimized for quick performance.
- **Minimal memory usage**: The program uses temporary files to store the path, reducing memory footprint.
- **Console output**: The program prints the maze dimensions, the positions of the start and end points, and the number of steps in the solution.
- **Error handling**: The program checks for input file validity and other runtime errors.

## 📁 Files
- **`main.c`**: The main file that makes takes parameters and uses functions from other files.
- **`mazeSolver.c`**: File that uses maze solving algorithm BFS.
- **`printMovesToConsole.c`**: File containing functions for printing the moves to the console.

## 💻 Compilation
1. 
   ```bash
   gcc -o mazeSolver main.c printMovesToConsole.c mazeSolver.c

## 🔨 Usage
1. Compile the files and run the program:
   ```bash
   gcc -o mazeSolver main.c printMovesToConsole.c mazeSolver.c
   ./mazeSolver <maze_name>
2. Example of a maze:
   ```bash
   ######
   #P   #
   # ## #
   #  #K#
   ######
P is the beggining of the maze and K is the ending.    
   

## 🙋‍♂️ Authors
- **Jakub Sztobryn** ~ Warsaw University of Technology student
