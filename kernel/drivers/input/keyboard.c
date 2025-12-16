#include <stdint.h>
#include "drivers/video/vga.h" // Only allowed for debugging; rest is done through console
#include "arch/x86/io.h"

#define KBD_DATA_PORT 0x60
#define KBD_STATUS_PORT 0x64

static uint8_t shift_down = 0;

// Reads a scancode if available; returns 0 if nothing available
static uint8_t kbd_try_read_scancode(void)
{
    uint8_t status = inb(KBD_STATUS_PORT);
    if ((status & 0x01) == 0)
        return 0; // output buffer empty
    return inb(KBD_DATA_PORT);
}

// Super tiny scancode set 1 map (QEMU default): scancode -> ASCII
// 0 means "ignore"
static const char scancode_to_ascii[128] = {
    /* 0x00 */ 0,
    0,
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    '0',
    '-',
    '=',
    '\b',
    /* 0x0F */ '\t',
    'q',
    'w',
    'e',
    'r',
    't',
    'y',
    'u',
    'i',
    'o',
    'p',
    '[',
    ']',
    '\n',
    0,
    /* 0x1E */ 'a',
    's',
    'd',
    'f',
    'g',
    'h',
    'j',
    'k',
    'l',
    ';',
    '\'',
    '`',
    0,
    '\\',
    /* 0x2C */ 'z',
    'x',
    'c',
    'v',
    'b',
    'n',
    'm',
    ',',
    '.',
    '/',
    0,
    '*',
    0,
    ' ',
    // rest left as 0
};

static const char scancode_to_ascii_shift[128] = {
    /* ... */ 0,
    0,
    '!',
    '@',
    '#',
    '$',
    '%',
    '^',
    '&',
    '*',
    '(',
    ')',
    '_',
    '+',
    '\b',
    /* ... */ '\t',
    'Q',
    'W',
    'E',
    'R',
    'T',
    'Y',
    'U',
    'I',
    'O',
    'P',
    '{',
    '}',
    '\n',
    0,
    /* ... */ 'A',
    'S',
    'D',
    'F',
    'G',
    'H',
    'J',
    'K',
    'L',
    ':',
    '"',
    '~',
    0,
    '|',
    /* ... */ 'Z',
    'X',
    'C',
    'V',
    'B',
    'N',
    'M',
    '<',
    '>',
    '?',
    0,
    '*',
    0,
    ' ',
};

static void handle_modifier(uint8_t sc)
{
    uint8_t released = sc & 0x80;
    uint8_t code = sc & 0x7F;

    if (code == 0x2A || code == 0x36)
    { // LShift or RShift
        shift_down = released ? 0 : 1;
    }
}

void keyboard_debug_poll_and_print(void)
{
    uint8_t sc = kbd_try_read_scancode();
    if (sc == 0)
        return;

    vga_print_hex(sc);
    vga_write(" ");
}

int keyboard_try_get_char(char *out)
{
    uint8_t sc = kbd_try_read_scancode();
    if (sc == 0)
        return 0;

    handle_modifier(sc);

    // ignore releases
    if (sc & 0x80)
        return 0;

    uint8_t code = sc & 0x7F;
    if (code >= 128)
        return 0;

    char c = shift_down ? scancode_to_ascii_shift[code]
                        : scancode_to_ascii[code];
    if (!c)
        return 0;

    *out = c;
    return 1;
}