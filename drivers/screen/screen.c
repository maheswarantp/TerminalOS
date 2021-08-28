#include "screen.h"

void set_char_at_video_memory(char character, int offset)
{
    u8 *VIDEO_MEMORY = (u8 *)VIDEO_ADDRESS;
    VIDEO_MEMORY[offset] = character;
}

void set_color_at_video_memory(int COLOR, int offset)
{
    u8 *VIDEO_MEMORY = (u8 *)VIDEO_ADDRESS;
    VIDEO_MEMORY[offset + 1] = COLOR;
}

int get_row_from_offset(int offset)
{
    return offset / (2 * MAX_COLS);
}

int get_offset(int col, int row)
{
    return 2*(row * MAX_COLS + col);
}

int move_offset_to_new_line(int offset)
{
    return get_offset(0, get_row_from_offset(offset) + 1);
}

int get_current_color()
{
    u8 *VIDEO_MEMORY = (u8 *)VIDEO_ADDRESS;
    int offset = get_cursor();
    return VIDEO_MEMORY[offset + 1];
}

void clear_screen()
{
    int i;
    for(i=0; i < MAX_COLS * MAX_ROWS; i++)
        set_char_at_video_memory(' ', i * 2);
    set_cursor(get_offset(0, 0));
}

int scroll_in(int offset)
{   
    memory_copy(
        (char *) (get_offset(0, 1) + VIDEO_ADDRESS),
        (char *) (get_offset(0, 0) + VIDEO_ADDRESS),
        MAX_COLS * (MAX_ROWS - 1) * 2
        );

    int col;
    for (col = 0; col < MAX_COLS; col++) 
        set_char_at_video_memory(' ', get_offset(col, MAX_ROWS - 1));

    return offset - 2 * MAX_COLS;
}

int print_char(char c, int col, int row, char attr) {
    u8 *vidmem = (u8*) VIDEO_ADDRESS;
    if (!attr) attr = WHITE;

    /* Error control: print a red 'E' if the coords aren't right */
    if (col >= MAX_COLS || row >= MAX_ROWS) {
        vidmem[2*(MAX_COLS)*(MAX_ROWS)-2] = 'E';
        vidmem[2*(MAX_COLS)*(MAX_ROWS)-1] = WHITE * 16 + RED;
        return get_offset(col, row);
    }

    int offset;
    if (col >= 0 && row >= 0) offset = get_offset(col, row);
    else offset = get_cursor();

    if (c == '\n') {
        row = get_row_from_offset(offset);
        offset = get_offset(0, row+1);
    } else if (c == 0x08) { /* Backspace */
        vidmem[offset] = ' ';
        vidmem[offset+1] = attr;
    } else {
        vidmem[offset] = c;
        vidmem[offset+1] = attr;
        offset += 2;
    }

    /* Check if the offset is over screen size and scroll */
    if (offset >= MAX_ROWS * MAX_COLS * 2) {
        int i;
        for (i = 1; i < MAX_ROWS; i++) 
            memory_copy((u8*)(get_offset(0, i) + VIDEO_ADDRESS),
                        (u8*)(get_offset(0, i-1) + VIDEO_ADDRESS),
                        MAX_COLS * 2);

        /* Blank last line */
        char *last_line = (char*) (get_offset(0, MAX_ROWS-1) + (u8*) VIDEO_ADDRESS);
        for (i = 0; i < MAX_COLS * 2; i++) last_line[i] = 0;

        offset -= 2 * MAX_COLS;
    }

    set_cursor(offset);
    return offset;
}