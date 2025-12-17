#pragma once
#include <stdint.h>

typedef struct 
{
    void (*clear)(void);
    void (*putc)(char c);
    void (*backspace)(void);
    void (*set_attr)(uint8_t attr); // Color later
} console_backend_t;

void console_set_backend(const console_backend_t* backend);
const console_backend_t* console_backend(void);
