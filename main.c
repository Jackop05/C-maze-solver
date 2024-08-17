#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "mazeSolver.h"
#include "printMovesToConsole.h"



int main(int argc, char *argv[]) {

    // Zmienne odnoszace sie do wysokosci i szerokosci pliku
    int width = 0;
    int height = 0;
    int currentRows = 0;
    int currentCols = 0;

    // Zmienne odnoszace sie do pozycji P oraz K w pliku
    int pLocationX;
    int pLocationY;
    int kLocationX;
    int kLocationY;
    
    // Sprawdzamy czy zosala podana odpowiednią ilość argumentów
    if (argc != 2) {
        fprintf(stderr, "Złe parametry wejściowe. Poprawne użycie: <maze_file>\n");
        exit(106);
    }



    // Otwieramy plik do odczytu i zapisu
    FILE *maze;
    maze = fopen(argv[1], "r+");
    if(maze == NULL){
        perror("Nie mozna otworzyc pliku");
        exit(101);
    }

    // Sprawdzamy pozycje w bajtach P oraz K
    char c;
    while((c = fgetc(maze)) != EOF) {
        if(c == 'P'){
            pLocationX = currentCols;
            pLocationY = currentRows;
        }
        if(c == 'K'){
            kLocationX = currentCols;
            kLocationY = currentRows;
        }
        if(c == '\n'){
            currentRows++;
            if(width < currentCols){
                width = currentCols;
            }
            currentCols = 0;
        } else {
            currentCols++;
        }
    }
    height = currentRows;



    // Stworzenieplikow  tymczasowych dla sciezki wyjscia z labiryntu
    FILE *pathX = tmpfile();
    FILE *pathY = tmpfile();
    if(pathX == NULL || pathY == NULL){
        perror("Nie mozna utworzyc pliku");
        exit(101);
    }

    // Ustawienie wskaznika w pliku na poczatek
    if(fseek(maze, 0, SEEK_SET) != 0){
        perror("Nie mozna otworzyc pliku");
        exit(101);
    }



    // Wywolanie algorytmu bfs
    printf("Szerokosc: %d, Wysokosc: %d, wspolrzedna X punktu start: %d, wspolrzedna Y punktu start: %d, wspolrzedna X punktu koniec: %d, wspolrzedna Y punktu koniec: %d\n", width, height, pLocationX, pLocationY, kLocationX, kLocationY);
    int pathLength = bfs(width, height, pLocationX, pLocationY, kLocationX, kLocationY, pathX, pathY, maze);

    pathLength = printMoveToConsole(pathX, pathY, pathLength);
    printf("Liczba krokow: %d\n", pathLength);

    fclose(pathX);
    fclose(pathY);
}