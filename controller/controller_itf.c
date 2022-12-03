#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "controller_itf.h"
#include "controller.h"
#include "util.h"

#define MAX_NUM_PARAMETERS 128

typedef struct
{
    itf_controller_t itf;
    controller_t controller;
    itf_commander_t *cmder;
} controller_itf_obj_t;

// TODO use dynamic array
static int input(void *p, int length, char *buf)
{
    if (p == NULL)
        return -1;

    controller_itf_obj_t *ins = (controller_itf_obj_t *)p;
    char *params[MAX_NUM_PARAMETERS] = {0};
    int cnt = 0;

    int start = 0;
    int end = 0;
    for (int i = 0; i < length; i++)
    {
        if (cnt >= MAX_NUM_PARAMETERS)
        {
            break;
        }

        if ((buf[i] == ' ') || (i == length - 1))
        {
            end = i;
            if ((end - start) > 0)
            {
                char *ns = malloc(end - start + 1);
                memcpy(ns, buf[start], end - start);
                ns[end - start] = '\0';
                params[cnt++] = ns;
            }

            start = i + 1;
        }
    }

    ITF_CALL(ins->cmder, call, cnt, params);

    // free allocated memory
    for (int i = 0; i < cnt; i++)
    {
        free(params[i]);
    }

    return 0;
}

static int set_stdout(void *p, itf_writer_t *writer)
{
    if (p == NULL)
        return -1;
    controller_itf_obj_t *ins = p;
    ins->controller.cstdout = p;
}

int init(controller_itf_obj_t *p)
{
}
int deinit() {}

itf_controller_t *controller_itf_new(itf_writer_t *writer)
{
    itf_commander_t *cmder = commander_itf_new(writer);
    if (cmder == NULL)
    {
        return NULL;
    }

    controller_itf_obj_t *ctrler = malloc(sizeof(controller_itf_obj_t));
    memset(ctrler, 0, sizeof(controller_itf_obj_t));

    ctrler->cmder = cmder;

    ctrler->itf.p = ctrler;
    ctrler->itf.input = input;
    ctrler->itf.set_stdout = set_stdout;

    return ctrler;
}