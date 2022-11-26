#include "echo.h"
#include <stdio.h>

static void entry(void *p, int argc, const char **argv, itf_writer_t *out)
{
    printf("echo cmd\r\n");
}

void echo_cmd_init(echo_cmd_t *p)
{
    p->name = "echo";
    p->cmd.entry = entry;
    p->cmd.p = p;
}