#ifndef __COMMANDER_H__
#define __COMMANDER_H__

#include "cdef/def_commander.h"
#include "cdef/def_command.h"
#include "def/def_container.h"

typedef struct
{
    itf_writer_t *outobj;
    int counter_cmd;
    itf_container_t *conta;
} commander_t;

int commander_init(commander_t *p, itf_writer_t *outobj);
int commander_deinit(commander_t *p);
int commander_set_stdout(commander_t *p, itf_writer_t *outobj);
int commander_register(commander_t *p, const char *cmd_name, itf_command_t *cmd);
int commander_call(commander_t *p, int argc, const char **argv);

#endif