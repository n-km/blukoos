#include "console/shell/shell.h"
#include "console/shell/command.h"
#include "console/console.h"
#include "console/console_backend.h"
#include "lib/string.h"

#include <stddef.h>

extern const command_t __cmd_start[];
extern const command_t __cmd_end[];

/* very small argv splitter: "cmd arg1 arg2" */
static int split_args(char *buf, char **argv, int argv_max)
{
    int argc = 0;
    char *p = buf;

    while (*p && argc < argv_max)
    {
        while (*p == ' ')
            p++;
        if (!*p)
            break;

        argv[argc++] = p;

        while (*p && *p != ' ')
            p++;
        if (*p)
            *p++ = '\0';
    }

    return argc;
}

static int kstrcmp(const char *a, const char *b)
{
    while (*a && (*a == *b))
    {
        a++;
        b++;
    }
    return (unsigned char)*a - (unsigned char)*b;
}

static int streq(const char *a, const char *b) { return kstrcmp(a, b) == 0; }

void command_execute(const char *line)
{
    if (!line || !line[0])
        return;

    /* copy to a mutable buffer for tokenizing */
    char buf[128];
    int i = 0;
    for (; line[i] && i < (int)sizeof(buf) - 1; i++)
        buf[i] = line[i];
    buf[i] = '\0';

    char *argv[8];
    int argc = split_args(buf, argv, 8);
    if (argc == 0)
        return;

    for (const command_t *cmd = __cmd_start; cmd < __cmd_end; cmd++)
    {
        if (cmd->name && streq(argv[0], cmd->name))
        {
            (void)cmd->run(argc, argv);
            return;
        }
    }

    console_write("Unknown command: ");
    console_writeln(argv[0]);
}
