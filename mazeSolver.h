#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void changeValueAtIndex(FILE *file, int index, int newValue);
int readValueAtIndex(FILE *file, int index);
int bfs(int width, int height, int startX, int startY, int endX, int endY, FILE *pathX, FILE *pathY, FILE *maze);
