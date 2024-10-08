# 🔢 Maze Solver Program

## 📝 Overview
This C program is a **high-performance maze solver** designed to solve mazes quickly and with minimal RAM usage. It utilizes an efficient Breadth-First Search (BFS) algorithm to find the shortest path from the start position (denoted as 'P') to the end position (denoted as 'K') in a maze file.

The program reads a maze from a file, finds the positions of the start ('P') and end ('K') points, and computes the shortest path between them. The number of minimal steps to solve the maze is printed ot console. Maze file is transformed, where **`X`** signs means that this tile was visited and **`@`** means it is the shortest path from the start to the end.

![image](https://github.com/user-attachments/assets/8dd1bae0-24b4-4462-a47c-f821cc26aec2)
![image](https://github.com/user-attachments/assets/0091c63d-e245-4129-b948-3e65c298bb1d)
![image](https://github.com/user-attachments/assets/2954a0ab-df73-4a2d-80eb-5f74a3f82b1f)


## 💡 Features
- **Fast execution**: The BFS algorithm is optimized for quick performance.
- **Minimal memory usage**: The program uses temporary files to store the path, reducing memory footprint.
- **Console output**: The program prints the maze dimensions, the positions of the start and end points, and the number of steps in the solution.
- **Error handling**: The program checks for input file validity and other runtime errors.

## 📁 Files
- **`main.c`**: The main file that makes takes parameters and uses functions from other files.
- **`mazeSolver.c`**: File that uses maze solving algorithm BFS.
- **`printMovesToConsole.c`**: File containing functions for printing the moves to the console.

## 🔨 Usage
1. Compile the files:
   ```bash
   gcc -o mazeSolver main.c printMovesToConsole.c mazeSolver.c
2. Run the program:
   ```bash
   ./mazeSolver <maze_name>
4. Example of a maze:
   ```bash
   ######
   P    #
   # ## #
   #  # #
   ####K#
P is the beggining of the maze and K is the ending.    
   

## 🙋‍♂️ Authors
- **Jakub Sztobryn** ~ Warsaw University of Technology student
