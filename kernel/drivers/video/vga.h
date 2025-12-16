#pragma once
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

void vga_clear_screen(void);
void vga_write(const char* s);
void vga_write_line(const char* s);
void vga_putc(char c);
void vga_backspace(void);
void vga_print_hex(uint8_t val);
