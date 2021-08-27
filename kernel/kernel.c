#include "kernel.h"

// void user_input(char *input) {
//     if (strcmp(input, "END") == 0) {
//         shutdown();
//         asm volatile("hlt");
//     }
//     print_string(input);
//     print_string("\n>");
// }


void user_input(char* input)
{
    if(strcmp(input, "END") == 0)
    {
        print_string("Stopping CPU...Bie\n");
        asm volatile("hlt");
    } else if(strcmp(input,"C-G") == 0) 
    {
        change_color(GREEN_ON_BLACK);
    } else if(strcmp(input, "C-W") == 0)
    {
        change_color(WHITE_ON_BLACK);
    } else if(strcmp(input, "C-Y") == 0)
    {
        change_color(YELLOW_ON_BLACK);
    } else if(strcmp(input, "C-B") == 0){
        change_color(BLUE_ON_BLACK);
    } else if(strcmp(input, "CLS") == 0)
    {
        clear_screen();
    } else if(strcmp(input, "HELP") == 0)
    {
        print_help();
    } else {
        print_string(input);
        print_string("\n>");
    }
}

void print_help()
{
    print_string("-------------------------------------------------------------------------------\n");
    print_string("                                      HELP                                     \n");
    print_string("\n");
    print_string("# BOOT            Prints the bootscreen\n");
    print_string("# COLOR CHANGES\n");
    print_string("      - C-G       Changes foreground color to green\n");
    print_string("      - C-Y       Changes foreground color to yellow\n");
    print_string("      - C-B       Changes foreground color to blue\n");
    print_string("      - C-W       Changes foreground color to white\n");
    print_string("\n");
    print_string("# HELP\n");
    print_string("      - Type HELP to get help\n");
    print_string("\n");
    print_string("# CLS     Clears the screen \n\n");
    print_string("# HLT     Halts the CPU \n");
    print_string("-------------------------------------------------------------------------------\n");

}


void main()
{
    isr_install();
    irq_install();
    clear_screen();
    boot_screen();
}