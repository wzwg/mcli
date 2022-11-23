#include "echo.h"
#include <stdio.h>

static void entry(void *pd, const char **params, void *cstdout)
{
    printf("echo cmd\r\n");
}

void echo_cmd_init(echo_cmd_t *p)
{
    p->name = "echo";
    p->cmd.entry = entry;
    p->cmd.p = p;
}