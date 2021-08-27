#include "idt.h"

void set_idt_gate(int n, u32 handler)
{
    idt[n].low_offset = low_16(handler);        // lower 16 bit of callback
    idt[n].sel = KERNEL_CS;                     // kernel selector
    idt[n].always0 = 0;
    idt[n].flags = 0x8E;                        // flags
    idt[n].high_offset = high_16(handler);
}

void set_idt()
{
    idt_reg.base = (u32) &idt;
    idt_reg.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1;
    __asm__ __volatile__ ("lidtl (%0)"::"r" (&idt_reg));
}
