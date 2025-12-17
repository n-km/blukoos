#pragma once

typedef int (*command_fn_t)(int argc, char **argv);

typedef struct
{
    const char *name;
    const char *help;
    command_fn_t run;
} command_t;
