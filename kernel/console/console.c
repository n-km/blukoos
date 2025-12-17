#include "console/console.h"
#include "drivers/input/keyboard.h"
#include "console/console_backend.h"
#include "console/shell/shell.h"

#define LINE_MAX 128

static const console_backend_t *g_console_backend = 0;

static char line[LINE_MAX];
static int line_len = 0;

void console_set_backend(const console_backend_t *backend) { g_console_backend = backend; }
const console_backend_t *console_backend(void) { return g_console_backend; }

static void outc(char character)
{
    if (g_console_backend && g_console_backend->putc)
        g_console_backend->putc(character);
}

static void out_s(const char *string)
{
    for (int i = 0; string[i] != 0; i++)
        outc(string[i]);
}

static void prompt(void)
{
    out_s("> ");
}

static void submit_line(void)
{
    out_s("\n");
    command_execute(line);
    // out_s("You typed: ");
    // out_s(line);
    // out_s("\n");

    line_len = 0;
    line[0] = 0;

    prompt();
}

static void push_char(char character)
{
    if (line_len >= LINE_MAX - 1)
        return;
    line[line_len++] = character;
    line[line_len] = 0;
    outc(character);
}

static void do_backspace(void)
{
    if (line_len <= 0)
        return;
    line_len--;
    line[line_len] = 0;
    if (g_console_backend && g_console_backend->backspace)
        g_console_backend->backspace();
}

void console_init(void)
{
    if (g_console_backend && g_console_backend->clear)
        g_console_backend->clear();
    prompt();
}

void console_tick(void)
{
    char character;
    if (!keyboard_try_get_char(&character))
        return;

    if (character == '\n')
    {
        submit_line();
    }
    else if (character == '\b')
    {
        do_backspace();
    }
    else
    {
        push_char(character);
    }
}

void console_write(const char *string)
{
    out_s(string);
}

void console_writeln(const char *string)
{
    out_s(string);
    out_s("\n");
}

void console_info(const char *string) { console_writeln(string); };
void console_error(const char *string) { console_writeln(string); };
