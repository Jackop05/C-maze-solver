
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





bool is_text_file(const char *filename);
char bin_to_txt(char *mazename);