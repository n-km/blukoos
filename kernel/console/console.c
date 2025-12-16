#include "console/console.h"
#include "drivers/video/vga.h"
#include "drivers/input/keyboard.h"

#define LINE_MAX 128

static char line[LINE_MAX];
static int line_len = 0;

static void prompt(void)
{
    vga_write("> ");
}

static void submit_line(void)
{
    vga_write("\n");
    vga_write("You typed: ");
    vga_write(line);
    vga_write("\n");

    line_len = 0;
    line[0] = 0;

    prompt();
}

static void push_char(char c)
{
    if (line_len >= LINE_MAX - 1)
        return;
    line[line_len++] = c;
    line[line_len] = 0;
    vga_putc(c);
}

static void do_backspace(void)
{
    if (line_len <= 0)
        return;
    line_len--;
    line[line_len] = 0;
    vga_backspace();
}

void console_init(void)
{
    vga_clear_screen();
    prompt();
}

void console_tick(void)
{
    char c;
    if (!keyboard_try_get_char(&c))
        return;

    if (c == '\n')
    {
        submit_line();
    }
    else if (c == '\b')
    {
        do_backspace();
    }
    else
    {
        push_char(c);
    }
}
