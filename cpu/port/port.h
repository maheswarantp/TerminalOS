#ifndef PORT_H
#define PORT_H

#include "../types.h"

#define VGA_CTRL_REGISTER 0x3d4
#define VGA_DATA_REGISTER 0x3d5
#define VGA_OFFSET_LOW 0x0f
#define VGA_OFFSET_HIGH 0x0e

u8 port_byte_in(u16 port);
void port_byte_out(u16 port, u8 data);
void set_cursor(int offset);
int get_cursor();

#endif