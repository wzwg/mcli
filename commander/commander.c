#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "commander.h"
#include "commands/default_command.h"
#include "container/trie_container.h"

int commander_init(commander_t *p, itf_writer_t *stdout)
{
    if (p == NULL) return 0;

    memset(p, 0, sizeof(commander_t));

    p->conta = trie_container_new();

    commander_set_stdout(p, stdout);

    // initialize public interface 
    p->cmder.p = p;
    p->cmder.call = commander_call;
    p->cmder.register_cmd = commander_register;
    p->cmder.set_stdout = commander_set_stdout;

    register_builtin_commands(&p->cmder);

    return 0;
}

int commander_set_stdout(commander_t *p, itf_writer_t *stdout)
{
    p->istdout = stdout;
}


int commander_register(commander_t *p, const char *cmd_name, itf_command_t *cmd) 
{
    int ret = 0;

    if (p == NULL) return 0;
    if (cmd == NULL) return 0;
    if (cmd_name == NULL) return 0;

    ret = p->conta->add_command(p->conta->p, cmd_name, cmd);
    if (ret != 0) return ret;

    p->counter_cmd++;

    return 0;
}

int commander_call(commander_t *p, int argc, const char **argv)
{
    if (p == NULL) return 0;

    itf_command_t *cmd = p->conta->find_command(p->conta->p, argv);
    if (cmd != NULL) {
        cmd->entry(cmd->p,  argc, argv, p->istdout);
    }
}