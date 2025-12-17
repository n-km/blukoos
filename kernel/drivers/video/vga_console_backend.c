#include "console/console_backend.h"
#include "drivers/video/vga.h"

static void vga_clear_adapter(void) { vga_clear_screen(); }
static void vga_putc_adapter(char c) { vga_putc(c); }
static void vga_backspace_adapter(void) { vga_backspace(); }
// static void vga_set_attr_adapter(uint8_t attr) { (void)attr; }

const console_backend_t VGA_CONSOLE_BACKEND = {
    .clear = vga_clear_adapter,
    .putc = vga_putc_adapter,
    .backspace = vga_backspace_adapter,
    .set_attr = 0, // Later vga_set_attr_adapter
};