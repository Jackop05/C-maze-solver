#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int printMoveToConsole(FILE *pathX, FILE *pathY, int pathLength) {
    
    // Tworze podstawowe zmienne
    char newDirection = ' ';
    char lastDirection = ' ';
    int numberOfSameDirections = 1;
    int correctPath = 0;
    int lastX;
    int lastY;
    int newX;
    int newY;
    char buffer[6];



    // Odwracamy kolejnosc linii w plikach
    rewind(pathX);
    rewind(pathY);
    FILE *fileX = pathX;
    FILE *fileY = pathY;
    if(fileX == NULL || fileY == NULL){
        perror("Nie mozna otworzyc pliku");
        exit(101);
    }
    rewind(fileX);
    rewind(fileY);

    // Obsluguje pierwszych krokow
    if(fscanf(fileX, "%d", &lastX) != 1){
        perror("Nie mozna pobrac nowej wartosci z pliku");
        exit(105);
    }
    if(fscanf(fileY, "%d", &lastY) != 1){
        perror("Nie mozna pobrac nowej wartosci z pliku");
        exit(105);
    }
    if(fscanf(fileX, "%d", &lastX) != 1){
        perror("Nie mozna pobrac nowej wartosci z pliku");
        exit(105);
    }
    if(fscanf(fileY, "%d", &lastY) != 1){
        perror("Nie mozna pobrac nowej wartosci z pliku");
        exit(105);
    }
    if(fscanf(fileX, "%d", &newX) != 1){
        perror("Nie mozna pobrac nowej wartosci z pliku");
        exit(105);
    }
    if(fscanf(fileY, "%d", &newY) != 1){
        perror("Nie mozna pobrac nowej wartosci z pliku");
        exit(105);
    }

    // Ustawienie pierwszego kierunku
    if(newX > lastX) {
        lastDirection = 'E';
    } else if(newX < lastX) {
        lastDirection = 'W';
    } else if (newY > lastY) {
        lastDirection = 'S';
    } else if(newY < lastY) {
        lastDirection = 'N';
    }

    // Petla przechodzaca po sciezce
    for(int i = 3; i < pathLength-1; i++) { 
        
        // Nadanie nowych wartosci aktualnej sciezki
        if(fscanf(fileX, "%d", &newX) != 1){
            perror("Nie mozna pobrac nowej wartosci z pliku");
            exit(105);
        }
        if(fscanf(fileY, "%d", &newY) != 1){
            perror("Nie mozna pobrac nowej wartosci z pliku");
            exit(105);
        }

        // Ustawienie nowego kierunku
        if(newX > lastX) {
            newDirection = 'W';
        } else if(newX < lastX) {
            newDirection = 'E';
        } else if (newY > lastY) {
            newDirection = 'N';
        } else if(newY < lastY) {
            newDirection = 'S';
        }

        if (newDirection == lastDirection) {
            numberOfSameDirections += 1;
        } else {
            if(lastDirection != ' ') {
                correctPath += numberOfSameDirections;
                numberOfSameDirections = 1; 
            }       
        }                        

        lastDirection = newDirection;
        lastX = newX;
        lastY = newY;
    }  
    correctPath += numberOfSameDirections/2;

    fclose(fileX);
    fclose(fileY);

    return correctPath;
}
