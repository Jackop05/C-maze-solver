#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint32_t file_id;
    uint8_t escape;
    uint16_t columns;
    uint16_t lines;
    uint16_t entry_x;
    uint16_t entry_y;
    uint16_t exit_x;
    uint16_t exit_y;
    uint8_t reserved[12];
    uint32_t counter;
    uint32_t solution_offset;
    uint8_t separator;
    uint8_t wall;
    uint8_t path;
} FileHeader;
#pragma pack(pop)


typedef struct {
    uint8_t separator;
    uint8_t value;
    uint8_t count;
} CodeWord;
    
bool is_text_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Nie mozna otworzyc pliku");
        exit(101);
    }

    bool is_text = true;
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c < 32 && c != '\n' && c != '\r' && c != '\t') {
            is_text = false;
            break;
        }
    }

    fclose(file);
    return is_text;
}

char bin_to_txt(char *mazename){
    char* filename;
    int binarny = 0;
    FileHeader header;

    if (is_text_file(mazename)) 
    {
        filename = mazename;
    } 
    else 
    {
        binarny = 1;
  
        FILE *file = fopen(mazename, "rb");
        if (file == NULL) {
            perror("Nie mozna otworzyc pliku");
            exit(101);
        }
        // Odczytanie nagłówka pliku
        if(fread(&header, sizeof(header), 1, file) < 0){
            perror("Nie mozna pobrac nowej wartosci z pliku");
            exit(105);
        }
        filename = "labirynt.txt";

        FILE *out = fopen(filename, "w");
        if (file == NULL) {
            perror("Nie mozna otworzyc pliku");
            exit(101);
        }
        int x = 1;
        int y = 1;

        // Odczytanie i wyświetlenie słów kodowych
        for (int i = 0; i < header.counter; i++) {  
            CodeWord word;
            if(fread(&word, sizeof(word), 1, file) < 0){
                perror("Nie mozna pobrac nowej wartosci z pliku");
                exit(105);
            }
            for(int j = 0; j < word.count+1; j++) {
                if ((x == header.entry_x) && (y == header.entry_y)) {
                    if(fputc('P', out) == EOF){
                        perror("Nie mozna zapisac nowej wartosci do pliku");
                        exit(104);
                    }
                    
                } else if ((x == header.exit_x) && (y == header.exit_y)) {
                    if(fputc('K', out) == EOF){}
                        perror("Nie mozna zapisac nowej wartosci do pliku");
                        exit(104);
                    
                } else {
                    if (word.value == header.wall) {
                        if(fputc('X', out) == EOF){
                            perror("Nie mozna zapisac nowej wartosci do pliku");
                            exit(104);
                        }
                    } else {
                        if(fputc(' ', out) == EOF){
                            perror("Nie mozna zapisac nowej wartosci do pliku");
                            exit(104);
                        }
                    } 
		   
		    if ((word.value != header.wall) && (word.value != header.path)){
			    fprintf(stderr, "Bledne slowa w danych kodowych w pliku binarnym");
			    exit(102); 	
		    }
                }

                x++;

                if (x == header.lines+1) {
                    if(fputc('\n', out) == EOF){
                        perror("Nie mozna zapisac nowej wartosci do pliku");
                        exit(104);
                    }
                    y++;
                    x = 1;
                }
            }
        }
        
        fclose(out);
        fclose(file);
    }	
    return *filename;
}