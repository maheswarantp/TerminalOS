#ifndef SCREEN_H
#define SCREEN_H

#include "../../cpu/port/port.h"
#include "../../cpu/types.h"
#include "../../libc/mem/mem.h"

#define VIDEO_ADDRESS 0xb8000
#define MAX_COLS 80
#define MAX_ROWS 25

#define WHITE_ON_BLACK 0x0f
#define RED_ON_WHITE 0xFC
#define GREEN_ON_BLACK 0x0A
#define YELLOW_ON_BLACK 0x0e
#define BLUE_ON_BLACK 0x09

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