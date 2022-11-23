#include <stdlib.h>
#include "trie_container.h"
#include "trie.h"

typedef struct
{
    itf_container_t conta;
    trie_t trie;
} trie_container_t;

static int add_command(void *p, const char *name, void *data)
{
    if (p == NULL)
        return -1;
    trie_container_t *conta = (trie_container_t *)p;

    int ret = trie_add_cmd(&conta->trie.root, name, data);
    if (ret != 0)
    {
        return ret;
    }
}

static void *find_command(void *p, const char *name)
{
    if (p == NULL)
        return NULL;
    trie_container_t *conta = (trie_container_t *)p;

    trie_node_t *node = trie_find_command_node(&conta->trie.root, name);
    if (node != NULL)
    {
        return node->ud;
    }

    return NULL;
}
// status: 1-indicate end of a name; 2- indicate end of all
static int get_optional_commands(void *p, stream_t stream)
{
    // TODO
    if (p == NULL)
        return -1;
}

itf_container_t *trie_container_new()
{
    trie_container_t *conta = malloc(sizeof(trie_container_t));
    trie_init(&conta->trie);
    conta->conta.p = conta;
    conta->conta.add_command = add_command;
    conta->conta.find_command = find_command;
    conta->conta.get_optional_commands = get_optional_commands;

    return &conta->conta;
}