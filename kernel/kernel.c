#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* VGA-Treiber (Textmodus, 0xB8000) */
#define VGA_WIDTH  80
#define VGA_HEIGHT 25
#define VGA_MEMORY 0xB8000

static uint16_t* terminal_buffer = (uint16_t*) VGA_MEMORY;
static size_t terminal_row = 0;
static size_t terminal_column = 0;
static uint8_t terminal_color = 0x0F;  // Weiß auf Schwarz

static inline uint16_t vga_entry(char c, uint8_t color) {
    return (uint16_t) c | (uint16_t) color << 8;
}

static void terminal_initialize(void) {
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = 0x0F;

    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', terminal_color);
        }
    }
}

void terminal_putchar(char c) {
    if (c == '\n') {
        terminal_column = 0;
        terminal_row++;
        return;
    }
    const size_t index = terminal_row * VGA_WIDTH + terminal_column;
    terminal_buffer[index] = vga_entry(c, terminal_color);
    if (++terminal_column == VGA_WIDTH) {
        terminal_column = 0;
        terminal_row++;
    }
}

void terminal_writestring(const char* str) {
    while (*str) terminal_putchar(*str++);
}

/* Kernel-Hauptfunktion */
void kernel_main(void) {
    terminal_initialize();

    terminal_writestring("Hello, Kernel World!\n");
    terminal_writestring("This is a minimal OS.\n");
}