#include "console/shell/register.h"
#include "console/console.h"

static int run_echo(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        console_write(argv[i]);
        if (i + 1 < argc)
        {
            console_write(" ");
        }
    }
    console_writeln("");
    return 0;
}

REGISTER_COMMAND(cmd_echo) = {
    .name = "echo",
    .help = "echoechoechoecho",
    .run = run_echo,
};
