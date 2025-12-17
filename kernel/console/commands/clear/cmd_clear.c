#include "console/shell/register.h"
#include "console/console_backend.h"

static int run_clear(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    const console_backend_t *b = console_backend();
    if (b && b->clear)
        b->clear();
    return 0;
}

REGISTER_COMMAND(cmd_clear) = {
    .name = "clear",
    .help = "clear screen",
    .run = run_clear,
};
