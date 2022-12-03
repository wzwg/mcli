#include <stdlib.h>
#include "commander_itf.h"
#include "commander.h"

typedef struct
{
    itf_commander_t itf;
    commander_t commander;
} commander_itf_t;

static int register_cmd(void *p, const char *cmd_name, itf_command_t *cmd)
{
    commander_itf_t *self = (commander_itf_t *)p;
    if (self == NULL)
        return -1;
    return commander_register(&self->commander, cmd_name, cmd);
}
static int call(void *p, int argc, const char **argv)
{
    commander_itf_t *self = (commander_itf_t *)p;
    if (self == NULL)
        return -1;

    return commander_call(&self->commander, argc, argv);
}
static int set_stdout(void *p, itf_writer_t *writer)
{
    commander_itf_t *self = (commander_itf_t *)p;
    if (self == NULL)
        return -1;
    return commander_set_stdout(&self->commander, writer);
}

itf_commander_t *commander_itf_new(itf_writer_t *cstdout)
{
    commander_itf_t *cmder = malloc(sizeof(commander_itf_t));
    commander_init(&cmder->commander, cstdout);

    // initialize public interface
    cmder->itf.p = cmder;
    cmder->itf.call = call;
    cmder->itf.register_cmd = register_cmd;
    cmder->itf.set_stdout = set_stdout;

    return &cmder->itf;
}

int commander_itf_deinit(itf_commander_t *p)
{
    // TODO
    return 0;
}