#ifndef __COMMANDER_H__
#define __COMMANDER_H__

#include "def/def_command.h"
#include "def/def_container.h"


typedef struct {
    int counter_cmd;
    itf_container_t *conta;
}commander_t;

int commander_init(commander_t *p);
int commander_register(commander_t *p, char *cmd_name, itf_command_t *cmd);
int commander_call(commander_t *p, char *param);

#endif