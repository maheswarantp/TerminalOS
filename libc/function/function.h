#ifndef FUNCTION_H
#define FUNCTION_H

#include "../../cpu/types.h"
#include "../../drivers/screen/screen.h"
#include "../string/string.h"

#define UNUSED(x) (void)(x)

void change_color(int COLOR);
void change_background_color(char *COLOR);
#endif
