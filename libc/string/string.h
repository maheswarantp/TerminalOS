#ifndef STRING_H
#define STRING_H

#include "../../drivers/screen/screen.h"
#include "../../cpu/port/port.h"

void print_string(char* string);
void print_decimal(int val);
void print_hex(int val);
void print_backspace();
int strlen(char s[]);
void reverse(char s[]);
void backspace(char s[]);
void append(char s[], char n);
int strcmp(char s1[], char s2[]);

#endif