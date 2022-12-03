#ifndef __DEF_COMMANDER_H__
#define __DEF_COMMANDER_H__

#include <stdint.h>
#include "def_command.h"
#include "def_io.h"

typedef struct
{
    void *p;
    int (*register_cmd)(void *p, const char *cmd_name, itf_command_t *cmd);
    int (*call)(void *p, int argc, const char **argv);
    int (*set_outobj)(void *p, itf_writer_t *writer);
} itf_commander_t;

#endif