#include "string.h"

void print_string(char* string)
{
    int offset = get_cursor();
    int i = 0;
    while(string[i] != 0)
    {
        if(offset >= MAX_ROWS * MAX_COLS * 2)
            offset = scroll_in(offset);

        if(string[i] != '\n')                // print regular character
        {
            set_char_at_video_memory(string[i], offset);    
            offset += 2;
        } else {                            // newline with '\n' symbol
            offset = move_offset_to_new_line(offset);
        }
        i++;
    }
    set_cursor(offset);
}

void print_decimal(int val)                 // prints number in decimal ascii
{
    char string[9] = "00000000";
    int n = 7;
    int temp;
    while(val != 0)
    {
        temp = val % 10;
        val = val / 10;
        n--;
    }
    print_string(string);
    print_string("D");
}

void print_hex(int val)                     // prints number in hex ascii
{
    char string[9] = "00000000";
    int n = 7;
    int temp;
    print_string("0x");
    while(val != 0)
    {
        temp = val % 16;
        val = val / 16;
        if(temp < 10 && temp >= 0)
            string[n] = temp + '0';
        else
            string[n] = temp + 7 + '0';
        n--;
    }
    print_string(string);
}

void print_backspace() {
    int offset = get_cursor()-2;
    int row = get_row_from_offset(offset);
    int col = (offset - (get_row_from_offset(offset)*2*MAX_COLS))/2;
    int COLOR = get_current_color();
    print_char(0x08, col, row, COLOR);
}

int strlen(char s[])                        // count len of string
{
    int i = 0;
    while(s[i] != '\0') ++i;
    return i;
}

void reverse(char s[])                     // reverses a string
{
    int c, i, j;
    for(i = 0, j = strlen(s) - 1;i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void backspace(char s[])
{
    int len = strlen(s);
    s[len - 1] = '\0';
}

void append(char s[], char c)
{
    int len = strlen(s);
    s[len] = c;
    s[len + 1] = '\0';
}

int strcmp(char s1[], char s2[])
{
    int i;
    for(i = 0; s1[i] == s2[i]; i++)
        if(s1[i] == '\0') return 0;

    return s1[i] - s2[i];
}

