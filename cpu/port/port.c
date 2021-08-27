#include "port.h"

u8 port_byte_in(u16 port)               // read from a port
{ 
    u8 result;
    __asm__("in %%dx, %%al":"=a" (result):"d"(port));
    return result;
}

void port_byte_out(u16 port, u8 data)   // send to a port
{
    __asm__("out %%al, %%dx"::"a"(data), "d"(port));
}

void set_cursor(int offset)             // set cursor on an offset
{
    offset /= 2;
    port_byte_out(VGA_CTRL_REGISTER, VGA_OFFSET_HIGH);
    port_byte_out(VGA_DATA_REGISTER, (u8) (offset >> 8));
    port_byte_out(VGA_CTRL_REGISTER, VGA_OFFSET_LOW);
    port_byte_out(VGA_DATA_REGISTER, (u8) (offset & 0xff));
}

int get_cursor()
{
    port_byte_out(VGA_CTRL_REGISTER, VGA_OFFSET_HIGH);
    int offset = port_byte_in(VGA_DATA_REGISTER) << 8;
    port_byte_out(VGA_CTRL_REGISTER, VGA_OFFSET_LOW);
    offset += port_byte_in(VGA_DATA_REGISTER);
    return offset * 2;
}