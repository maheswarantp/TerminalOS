#include "function.h"

void change_color(int COLOR)
{
    int i;
    for(i = 0; i < MAX_COLS*MAX_ROWS; i++)
        set_color_at_video_memory(COLOR, i*2);
}