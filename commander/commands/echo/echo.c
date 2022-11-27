#include "echo.h"
#include <stdio.h>

static int entry(void *p, int argc, const char **argv, itf_writer_t *out)
{
    for (int i = 1; i < argc; i++)
    {
        out->write(out->p, argv[i], strlen(argv[i]));
        if (i < argc)
        {
            out->write(out->p, " ", 1);
        }
    }

    return 0;
}

void echo_cmd_init(echo_cmd_t *p)
{
    p->name = "echo";
    p->cmd.entry = entry;
    p->cmd.p = p;
}