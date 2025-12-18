#pragma once
#include <stddef.h>
#include "../drivers/video/vga.h"

void console_init(void);
void console_tick(void); // call repeatedly in main loop

void console_write_line_color(size_t row, const char* str, size_t len, vga_color_t fg, vga_color_t bg);