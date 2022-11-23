#include <stdio.h>
#include <time.h>

#include "trie.h"
#include "commander.h"


void t1()
{
    trie_t trie;

    trie_node_t head;

    trie_init(&trie);
    trie_node_init(&head);

    // trie_add_cmd(&head, "hepp", 0);
    // trie_add_cmd(&trie.root, "hel", 0);
    // trie_add_cmd(&trie.root, "help", 0);
    // trie_add_cmd(&trie.root, "help1", 0);
    // trie_add_cmd(&trie.root, "help2", 0);

    // trie_add_cmd(&head, "are", 0);

    trie_list_all_commands(&trie.root);
    printf("head\r\n");
    trie_list_all_commands(&head);

    printf("hello");
    return 0;
}

int main(int argc, char **argv)
{
    commander_t cmder;

    commander_init(&cmder);

    commander_call(&cmder, "echo hi");

    return 0;
}
