#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "commander.h"
#include "commands/default_command.h"
#include "container/trie_container.h"

int commander_init(commander_t *p)
{
    if (p == NULL) return 0;

    memset(p, 0, sizeof(commander_t));

    p->conta = trie_container_new();

    register_builtin_commands(p);

    return 0;
}

int commander_register(commander_t *p, char *cmd_name, itf_command_t *cmd) 
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

int commander_call(commander_t *p, char *param)
{
    if (p == NULL) return 0;
    
    int length = strlen(param);

    char *cmd_name = malloc(length+1);
    char *cmd_param;
    for (int i=0; i<length; i++) {
        if (param[i] == ' ') {
            cmd_name[i] = '\0';
            if (i+1 <= length) {
                cmd_param = &param[i+1];
            }
            break;
        }
        cmd_name[i] = param[i];
    }

    itf_command_t *cmd = p->conta->find_command(p->conta->p, cmd_name);
    // trie_node_t *cmdNode = trie_find_command_node(&p->container.root, cmd_name);
    if (cmd != NULL) {
        cmd->entry(cmd->entry,  &cmd_param, 0);
    }
}