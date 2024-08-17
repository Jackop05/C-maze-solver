#include <stdio.h>
#include <stdlib.h>
#include <string.h>





void changeValueAtIndex(FILE *file, int index, int newValue) {

    // Przesunięcie wskaźnika pliku do odpowiedniej pozycji
    int position = index * 5;
    if(fseek(file, position, SEEK_SET) != 0){
        perror("Nie mozna otworzyc pliku");
        exit(101);
    }

    // Konwersja newValue na łańcuch znaków
    char newLine[6];
    if(snprintf(newLine, sizeof(newLine), "%04d\n", newValue) < 0){
        perror("Nie można zapisać nowej wartości do stringa");
        exit(103);
    }

    // Powrót do odpowiedniej pozycji w pliku i zapis zmodyfikowanej linii
    if(fseek(file, position, SEEK_SET) != 0){
        perror("Nie mozna otworzyc pliku");
        exit(101);
    }

    if(fputs(newLine, file) == EOF){
        perror("Nie mozna zapisac nowej wartosci do pliku");
        exit(104);
    }
}



int readValueAtIndex(FILE *file, int index) {

    // Przesunięcie wskaźnika pliku do odpowiedniej pozycji
    int position = index*5;
    if(fseek(file, position, SEEK_SET) != 0){
        perror("Nie mozna otworzyc pliku");
        exit(101);
    }

    // Odczytanie linii z pliku
    char line[6]; 
    if(fgets(line, sizeof(line), file) == NULL){
        perror("Nie mozna pobrac nowej wartosci z pliku");
        exit(105);
    }

    // Zwrocenie nowej liczby przekazanej z ciagu znakow
    int value = atoi(line);
    return value;
}



int bfs(int width, int height, int startX, int startY, int endX, int endY, FILE *pathX, FILE *pathY, FILE *maze){
    
    // Podstawowe zmienne dla bfs
    int steps = 0;
    char newElement;
    int currentX = startX;
    int currentY = startY;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int front = 0;
    int rear = 1; 



    // Tworzymy zbior plikow tymczasowych z historia przejsc dla wspolrzednych X oraz Y
    FILE *parentsX = tmpfile();
    FILE *parentsY = tmpfile();
    if(parentsX == NULL || parentsY == NULL){
        perror("Nie mozna otworzyc pliku");
        exit(101);
    }
    for(int i = 0; i < height; i++){
        for (int j = 0; j < width; j++) {
            fprintf(parentsX, "%s\n", "0000\n");
        }
    }
    for(int i = 0; i < height; i++){
        for (int j = 0; j < width; j++) {
            fprintf(parentsY, "%s\n", "0000\n");
        }
    }
    changeValueAtIndex(parentsY, currentX + width*currentY, currentX);
    changeValueAtIndex(parentsY, currentX + width*currentY, currentY);
    
    // Tworzymy zbior plikow tymczasowych z kolejka przejsc
    FILE *queueX = tmpfile();
    FILE *queueY = tmpfile();
    if(queueX == NULL || queueY == NULL){
        perror("Nie mozna otworzyc pliku");
        exit(101);
    }
    for(int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            fprintf(queueX, "%s\n", "0000\n");
        }
    }
    for(int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            fprintf(queueY, "%s\n", "0000\n");
        }
    }
    changeValueAtIndex(queueX, 0, currentX);
    changeValueAtIndex(queueY, 0, currentY);
    


    // Rozpoczynamy pętlę bfs
    while(front < rear){

        // Wczytujemy nowy punkt
        currentX = readValueAtIndex(queueX, front);
        currentY = readValueAtIndex(queueY, front);
        front++;

        // Oznaczamy nowy punkt jako '*', zeby bylo wiadomo ze w nim bylismy
        if(fseek(maze, currentX + (width+1)*currentY, SEEK_SET) != 0){
            perror("Nie mozna otworzyc pliku");
            exit(101);
        }
        if(fputc('*', maze) == EOF){
            perror("Nie mozna zapisac nowej wartosci do pliku");
            exit(104);
        }



        // Petla for pozwalajaca na obejrzenie wszystkich 4 kierunkow
        for(int i = 0; i < 4; i++){

            // Sprawdzamy wszystkie nowe kierunki
            int newX = currentX + dx[i];
            int newY = currentY + dy[i];


            
            // Sprawdzamy czy nowy kierunek jest poprawny
            if(newX > 0 && newY > 0 &&  newX < width && newY < height){

                // Ustawiamy wartosc odwiedzanego aktualnie punktu
                if(fseek(maze, newX + (width+1)*newY, SEEK_SET) != 0){
                    perror("Nie mozna otworzyc pliku");
                    exit(101);
                }
                newElement = fgetc(maze);
                if(newElement == EOF){
                    perror("Nie mozna pobrac nowej wartosci z pliku");
                    exit(105);
                }

                

                // Sprawdzamy czy nowy kierunek jest mozliwy do odwiedzenia
                if((newElement != 'X' && newElement != '*' && newElement != '\n') && (newElement == ' ' || newElement == 'K' || newElement == 'P')){

                    // Zapisujemy punkt z ktorego dotarlismy do nowego punktu 
                    changeValueAtIndex(parentsX, newX + width*newY, currentX);
                    changeValueAtIndex(parentsY, newX + width*newY, currentY);

                    // Sprawdzamy czy nowy punkt jest rowny 'K'
                    if(newElement == 'K'){
                        int x = newX;
                        int y = newY;
                        int pathIndex = 0;

                        // Przepisujemy sciezke po ktorej znalezlismy 'K'
                        while ((x != startX) || (y != startY)) {
                            
                            if(fseek(maze, x + (width+1)*y, SEEK_SET) != 0){
                                perror("Nie mozna otworzyc pliku");
                                exit(101);
                            };
                            if(fputc('@', maze) == EOF){
                                perror("Nie mozna zapisac nowej wartosci do pliku");
                                exit(104);
                            }
                            if(fprintf(pathX, "%d\n", x) < 0){
                                perror("Nie mozna zapisac nowej wartosci do pliku");
                                exit(104);
                            }
                            if(fprintf(pathY, "%d\n", y) < 0){
                                perror("Nie mozna zapisac nowej wartosci do pliku");
                                exit(104);
                            }
                            
                            int tempX = x;
                            x = readValueAtIndex(parentsX, tempX + width*y);
                            y = readValueAtIndex(parentsY, tempX + width*y);
                            pathIndex++;
                        }
                        
                        // Zapisujemy ostatni punkt do sciezki
                        if(fseek(maze, x + (width+1)*y, SEEK_SET) != 0){
                            perror("Nie mozna otworzyc pliku");
                            exit(101);
                        };
                        if(fputc('@', maze) == EOF){
                            perror("Nie mozna zapisac nowej wartosci do pliku");
                            exit(104);
                        }

                        // Zamykamy uzywane pliki
                        fclose(parentsX);
                        fclose(parentsY);
                        fclose(queueX);
                        fclose(queueY);

                        // Zwracamy dlugosc sciezki
                        return pathIndex+1;
                    } else {

                        // Zapisujemy punkt do kolejki 
                        changeValueAtIndex(queueX, rear, newX); 
                        changeValueAtIndex(queueY, rear, newY); 
                        rear++;
                    }
                } 
            }
        }
    }

    // Zamykamy uzywane pliki
    fclose(parentsX);
    fclose(parentsY);
    fclose(queueX);
    fclose(queueY);
}
