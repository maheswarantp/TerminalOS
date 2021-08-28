#ifndef SCREEN_H
#define SCREEN_H

#include "../../cpu/port/port.h"
#include "../../cpu/types.h"
#include "../../libc/mem/mem.h"

#define VIDEO_ADDRESS 0xb8000
#define MAX_COLS 80
#define MAX_ROWS 25

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LGRAY 7
#define DGRAY 8
#define LBLUE 9
#define LGREEN 10
#define LCYAN 11
#define LRED 12
#define LMAGENTA 13
#define YELLOW 14
#define WHITE 15



void set_char_at_video_memory(char character, int offset);
void set_color_at_video_memory(int offset, int FONT_COLOR);
int get_row_from_offset(int offset);
int get_offset(int col, int row);
int move_offset_to_new_line(int offset);
int get_current_color();
void clear_screen();
int scroll_in(int offset);
int print_char(char c, int col, int row, char attr);

#endif