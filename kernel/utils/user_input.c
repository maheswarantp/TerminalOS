#include "user_input.h"

void split_string(char s[], char s1[], char s2[])
{

    int i = 0, j = 0;
    while(s[i] != ' ')
    {
        if(i > 10) break;
        s1[i] = s[i];
        i++;
    }
    s1[i] = '\0';
    i++;
    while(s[i] != '\0')
    {
        if(j>10) break;
        s2[j] = s[i];
        i++;
        j++;
    }
    s2[j] = '\0';
}


void user_input(char* input)
{

    char *s1, *s2;

    if(strcmp(input, "END") == 0)
    {
        shutdown();
        asm volatile("hlt");
    } else if(strcmp(input,"C-G") == 0) 
    {
        change_color(GREEN);
    } else if(strcmp(input, "C-W") == 0)
    {
        change_color(WHITE);
    } else if(strcmp(input, "C-Y") == 0)
    {
        change_color(YELLOW);
    } else if(strcmp(input, "C-B") == 0){
        change_color(LBLUE);
    } else if(strcmp(input, "C-R") == 0){
        change_color(RED);
    } else if(strcmp(input, "C-BL") == 0){
        change_color(BLACK);
    } else if(strcmp(input, "CLS") == 0)
    {
        clear_screen();
    } else if(strcmp(input, "HELP") == 0)
    {
        print_help();
    } else if(strcmp(input, "BOOT") == 0) {
        clear_screen();
        int color = get_current_color();
        boot_screen();
        change_color(color);
    } else if(strcmp(input, "WHOAMI") == 0){
        print_string("Welcome to Terminal OS v2: Type and enter END to exit\n>");
        print_string("Author: max1712345\n");
        print_string("Source code: https://github.com/coding-geek1711/TerminalOS\n");
    } else {
        split_string(input, s1, s2);
        if(strcmp(s1, "ECHO") == 0)
            print_string(s2);
        else if(strcmp(s1, "LS") == 0)
            print_string("File system not implemented as of yet..");
        else if(strcmp(s1, "BG") == 0)
            change_background_color(s2);
        else 
            print_string("Not understood");
    }
    
    print_string("\n>");

}