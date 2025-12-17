#include "console/shell/register.h"
#include "console/console.h"

static int run_ping(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    console_writeln("pong");
    return 0;
}

REGISTER_COMMAND(cmd_ping) = {
    .name = "ping",
    .help = "ping -> pong",
    .run = run_ping,
};
