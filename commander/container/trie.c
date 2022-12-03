#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

static trie_node_t *trie_find_sib_by_data(trie_node_t *p, char d)
{
    if (p == NULL)
    {
        return NULL;
    }

    for (; p != NULL; p = p->sib)
    {
        if (p->data == d)
        {
            return p;
        }
    }

    return NULL;
}

static trie_node_t *trie_find_child_by_data(trie_node_t *p, char d)
{
    if (p == NULL)
        return NULL;

    return trie_find_sib_by_data(p->child, d);
}

// return nearly matched node, e.g have 'hel', input 'help', 'hel' matched, return node of 'l'
trie_node_t *trie_find_mathced_node(trie_node_t *p, const char *s, int *matchedCnt)
{
    trie_node_t *node = p;
    trie_node_t *matched = 0;

    if (p == NULL)
        return NULL;
    if (s == NULL)
        return NULL;

    for (int i = 0; s[i] != '\0'; i++)
    {
        node = trie_find_child_by_data(node, s[i]);
        if (node == NULL)
        {
            break;
        }
        matched = node;
        if (matchedCnt != NULL)
        {
            *matchedCnt = i + 1;
        }
    }

    return matched;
}

trie_node_t *trie_find_command_node(trie_node_t *p, const char *s)
{
    trie_node_t *node;
    int cnt;
    node = trie_find_mathced_node(p, s, &cnt);
    if (node == NULL)
        return NULL;
    if (cnt != strlen(s))
        return NULL;

    return node;
}

int trie_add_cmd(trie_node_t *t, const char *name, void *ud)
{
    if (name == NULL)
    {
        return 0;
    }
    trie_node_t *p = t;
    for (int i = 0; i < strlen(name); i++)
    {
        trie_node_t *n = trie_find_child_by_data(p, name[i]);
        if (n == NULL)
        {
            trie_node_t *newNode = malloc(sizeof(trie_node_t));
            newNode->data = name[i];
            newNode->parent = p;
            newNode->child = NULL;
            newNode->sib = p->child;
            newNode->isDone = false;
            p->child = newNode;

            n = newNode;
        }

        p = n;
    }

    if (p->isDone)
    {
        return -1; // error, repeated command name
    }

    p->isDone = true;
    p->ud = ud;

    return 0;
}

static void reverse_char_arrary(char arr[], int length)
{
    char t;
    int l = 0, r = length - 1;

    while (l < r)
    {
        t = arr[l];
        arr[l] = arr[r];
        arr[r] = t;

        l++;
        r--;
    }
}

static int trie_text_curup(trie_node_t *node, char buf[])
{
    int cnt = 0;
    if (node == NULL)
        return 0;
    if (buf == NULL)
        return 0;

    for (; node != NULL; cnt++)
    {
        buf[cnt] = node->data;
        node = node->parent;
    }

    reverse_char_arrary(buf, cnt - 1);

    return 0;
}

// static int trie_level_no(trie_node_t *node)
// {
//     int i = 0;

//     if (node == NULL)
//         return 0;

//     for (; node != NULL; i++)
//     {
//         node = node->parent;
//     }

//     return i;
// }

static void _trie_list_all_commands_dfs(trie_node_t *node)
{
    if (node == NULL)
        return;

    if (node->isDone)
    {
        char buf[CMDNAME_MAX_LENGTH + 1] = {'\0'};
        trie_text_curup(node, buf);
        printf("%s ", buf);
    }

    _trie_list_all_commands_dfs(node->child);
    _trie_list_all_commands_dfs(node->sib);
}

int trie_list_all_commands(trie_node_t *p)
{
    _trie_list_all_commands_dfs(p);
    return 0;
}

static void reset_data(void *data, int size)
{
    if ((data == NULL) || size == 0)
        return;

    memset(data, 0, size);
    return;
}

void trie_init(trie_t *t)
{
    if (t == NULL)
        return;

    reset_data(t, sizeof(trie_t));
}

void trie_deinit(trie_t *t)
{
    // TODO
}

void trie_node_init(trie_node_t *n)
{
    if (n == NULL)
        return;

    reset_data(n, sizeof(trie_node_t));
}

// implementation of the container interface

int (*add_command)(void *p, const char *name, void *data);
void *(*find_command)(void *p, const char *name);
// status: 1-indicate end of a name; 2- indicate end of all
int (*get_optional_commands)(void *p, void (*stream)(char c, char status));