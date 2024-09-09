# 🔢 Maze Solver Program

## 📝 Overview
This C program is a **high-performance maze solver** designed to solve mazes quickly and with minimal RAM usage. It utilizes an efficient Breadth-First Search (BFS) algorithm to find the shortest path from the start position (denoted as 'P') to the end position (denoted as 'K') in a maze file.

The program reads a maze from a file, finds the positions of the start ('P') and end ('K') points, and computes the shortest path between them. The number of minimal steps to solve the maze is printed ot console. Maze file is transformed, where **`X`** signs means that this tile was visited and **`@`** means it is the shortest path from the start to the end.

![image](https://github.com/user-attachments/assets/8dd1bae0-24b4-4462-a47c-f821cc26aec2)
![image](https://github.com/user-attachments/assets/95b5812d-1a11-4068-8fe2-b99795753771)


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
1. Compile the program:
   ```bash
   gcc -o mazeSolver main.c printMovesToConsole.c mazeSolver.c

## 🔨 Usage
1. Compile the files:
   ```bash
   gcc -o mazeSolver main.c printMovesToConsole.c mazeSolver.c
2. Run the program:
   ./mazeSolver <maze_name>
3. Example of a maze:
   ```bash
   ######
   P    #
   # ## #
   #  # #
   ####K#
P is the beggining of the maze and K is the ending.    
   

## 🙋‍♂️ Authors
- **Jakub Sztobryn** ~ Warsaw University of Technology student
