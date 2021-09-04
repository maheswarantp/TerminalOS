#include "keyboard.h"

#define BACKSPACE 0x0e
#define ENTER 0x1c
#define SC_MAX 57
#define SPACE 0x39
#define CAPS_KEYDOWN 0x3A
#define CAPS_KEYUP 0xBA 

int CAPS_ACTIVE = 0;            // 0 is false, 1 is active

static char key_buffer[256];

const char *sc_name[] = { "ERROR", "Esc", "1", "2", "3", "4", "5", "6", 
    "7", "8", "9", "0", "-", "=", "Backspace", "Tab", "Q", "W", "E", 
        "R", "T", "Y", "U", "I", "O", "P", "[", "]", "Enter", "Lctrl", 
        "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", "`", 
        "LShift", "\\", "Z", "X", "C", "V", "B", "N", "M", ",", ".", 
        "/", "RShift", "Keypad *", "LAlt", "Spacebar"
};

const char sc_ascii[] = { '?', '?', '1', '2', '3', '4', '5', '6',     
    '7', '8', '9', '0', '-', '=', '?', '?', 'Q', 'W', 'E', 'R', 'T', 'Y', 
        'U', 'I', 'O', 'P', '[', ']', '?', '?', 'A', 'S', 'D', 'F', 'G', 
        'H', 'J', 'K', 'L', ';', '\'', '`', '?', '\\', 'Z', 'X', 'C', 'V', 
        'B', 'N', 'M', ',', '.', '/', '?', '?', '?', ' '
};

static void keyboard_callback(registers_t regs)
{

    u8 scancode = port_byte_in(0x60);

    // print_string("Scan code is: ");
    // print_hex((int)scancode);
    // print_string("\n");

    if(scancode == 0x3A){
        // print_string("Caps on\n");
        CAPS_ACTIVE = 1 - CAPS_ACTIVE;
    }
    if(scancode >  SC_MAX) return;
    if(scancode == BACKSPACE)
    {
        int offset = get_cursor();
        int COL_NUMBER = offset % MAX_COLS;
        if(COL_NUMBER > 2)          // to not be able to backspace the command line ">"
        {
            backspace(key_buffer);
            print_backspace();
        }
    } else if (scancode == ENTER)
    {
        print_string("\n");
        user_input(key_buffer);
        key_buffer[0] = '\0';
    
    // } else if(scancode == CAPS_KEYDOWN) {
    //     print_string("caps");
    // }
    } else {
        char letter = sc_ascii[(int)scancode];
        if(CAPS_ACTIVE == 1)
        {
            if((int)scancode != SPACE)
                letter = letter + 0x20;
        }
        char str[2] = {letter, '\0'};
        append(key_buffer, letter);
        print_string(str);
    }
    UNUSED(regs);
}

void init_keyboard()
{
    register_interrupt_handler(IRQ1, keyboard_callback);
}

