#include "function.h"

void change_color(int COLOR)
{
    int i, ALL_COLOR, BACKGROUND_COLOR;
    ALL_COLOR = get_current_color();
    BACKGROUND_COLOR = ALL_COLOR / 16;
    ALL_COLOR =  BACKGROUND_COLOR * 16 + COLOR;
    for(i = 0; i < MAX_COLS*MAX_ROWS; i++)
        set_color_at_video_memory(ALL_COLOR, i*2);
}

void change_background_color(char *COLOR)
{
    if(COLOR[0] == 'G')
        background_change(GREEN);
    else if(COLOR[0] == 'B')
        background_change(BLUE);
    else if(COLOR[0] == 'Y')
        background_change(YELLOW);
    else if(COLOR[0] == 'W')
        background_change(WHITE);
    else if(COLOR[0] == 'R')
        background_change(RED);
    else 
        background_change(0x0);
    
}

void background_change(int COLOR)
{
    int i, ALL_COLOR, FOREGROUND_COLOR;
    ALL_COLOR = get_current_color();
    FOREGROUND_COLOR = ALL_COLOR % 16;
    ALL_COLOR = COLOR * 16 + FOREGROUND_COLOR;
    for(i = 0; i < MAX_COLS*MAX_ROWS; i++)
        set_color_at_video_memory(ALL_COLOR, i*2);
}