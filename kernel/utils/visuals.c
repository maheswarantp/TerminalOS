#include "visuals.h"

void boot_screen()
{
    change_color(WHITE);
    print_string("-------------------------------------------------------------------------------\n");
    print_string("  _______                  _             _    ____   _____ \n");
    print_string(" |__   __|                (_)           | |  / __ \\ / ____|\n");
    print_string("    | | ___ _ __ _ __ ___  _ _ __   __ _| | | |  | | (___  \n");
    print_string("    | |/ _ \\ '__| '_ ` _ \\| | '_ \\ / _` | | | |  | |\\___ \\ \n");
    print_string("    | |  __/ |  | | | | | | | | | | (_| | | | |__| |____) |\n");
    print_string("    |_|\\___|_|  |_| |_| |_|_|_| |_|\\__,_|_|  \\____/|_____/\n");
    print_string("\n");
    print_string("-------------------------------------------------------------------------------\n");
}

void shutdown()
{
    clear_screen();
    print_string("\n");
    print_string("\n");
    print_string("\n");    
    print_string("-------------------------------------------------------------------------------\n");
    print_string("                               POWEROFF SUCCESSFULL                            \n");
    print_string("-------------------------------------------------------------------------------\n");
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
