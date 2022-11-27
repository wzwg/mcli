#include "commander_itf.h"
#include "commander.h"
#include "commands/default_command.h"

typedef struct
{
    itf_commander_t itf;
    commander_t commander;
} commander_itf_t;

itf_commander_t *commander_itf_new(itf_writer_t *cstdout)
{
    commander_itf_t *cmder = malloc(sizeof(commander_itf_t));
    commander_init(&cmder->commander, cstdout);

    // initialize public interface
    cmder->itf.p = &cmder->commander;
    cmder->itf.call = commander_call;
    cmder->itf.register_cmd = commander_register;
    cmder->itf.set_stdout = commander_set_stdout;

    register_builtin_commands(&cmder->itf);

    return &cmder->itf;
}

int commander_itf_deinit(itf_commander_t *p)
{
    // TODO
}