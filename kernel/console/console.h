#pragma once
void console_init(void);
void console_tick(void); // call repeatedly in main loop

void console_write(const char* s);
void console_writeln(const char* s);

// void console_set_color(fg,bg);