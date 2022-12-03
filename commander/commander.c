#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "commander.h"
#include "container/trie_container.h"
#include "util.h"

int commander_init(commander_t *p, itf_writer_t *stdout)
{
    if (p == NULL)
        return 0;
    if (stdout == NULL)
        return -1;

    memset(p, 0, sizeof(commander_t));

    p->conta = trie_container_new();

    commander_set_stdout(p, stdout);

    return 0;
}

// internal data deinit
int commander_deinit(commander_t *p)
{
    // TODO
    trie_container_deinit(p->conta);
    free(p->conta);
    p->conta = NULL;

    return 0;
}

int commander_set_stdout(commander_t *p, itf_writer_t *stdout)
{
    p->cstdout = stdout;
    return 0;
}

int commander_register(commander_t *p, const char *cmd_name, itf_command_t *cmd)
{
    int ret = 0;

    if (p == NULL)
        return 0;
    if (cmd == NULL)
        return 0;
    if (cmd_name == NULL)
        return 0;

    ret = ITF_CALL(p->conta, add_command, cmd_name, cmd);
    if (ret != 0)
        return ret;

    p->counter_cmd++;

    return 0;
}

int commander_call(commander_t *p, int argc, const char **argv)
{
    if (p == NULL)
        return 0;
    if (argc < 1)
        return -1;

    itf_command_t *cmd = p->conta->find_command(p->conta->p, argv[0]);
    if (cmd != NULL)
    {
        return ITF_CALL(cmd, entry, argc, argv, p->cstdout);
    }

    return 0;
}
