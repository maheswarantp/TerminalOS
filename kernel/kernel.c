#include "kernel.h"


void main()
{
    isr_install();
    irq_install();
    clear_screen();
    boot_screen();
    print_string(">");
}