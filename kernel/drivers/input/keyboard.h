#pragma once

void keyboard_debug_poll_and_print(void);
int keyboard_try_get_char(char* out);  // 1 = got char, 0 = none
