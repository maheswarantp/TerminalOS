#ifndef IDT_H
#define IDT_H

#include "types.h"
#define KERNEL_CS 0x08

typedef struct 
{
    u16 low_offset;         // lower 16 bits of handler function
    u16 sel;                // kernel segment selector
    u8 always0;             // 8 bits always 0
    u8 flags;               
    /*
        Bit 7: interrupt present
        Bit 6-5: privilege level of caller (0 kernel, 3 user)
        Bit 4: 0 for interrupt gates
        Bit 3-0: 1110 == 14D === 32bit interrupt handler gate
    */
    u16 high_offset;        // higher 16 bits of handler function
} __attribute__((packed)) idt_gate_t;

typedef struct {
    u16 limit;
    u32 base;
} __attribute__((packed)) idt_register_t;

#define IDT_ENTRIES 256
idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_reg;

// Functions to set idt gate and to set idt
void set_idt_gate(int n, u32 handler);
void set_idt();

#endif