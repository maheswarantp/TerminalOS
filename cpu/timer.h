#ifndef TIMER_H
#define TIMER_H

#include "../libc/function/function.h"
#include "../drivers/screen/screen.h"
#include "isr.h"

void init_timer(u32 freq);

#endif