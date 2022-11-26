#ifndef __DEF_COMMANDER_H__
#define __DEF_COMMANDER_H__

#include <stdint.h>
#include "def_command.h"
#include "def_io.h"

typedef int (*writer_t)(void *p, uint8_t *buf, int length);

typedef struct
{
    void *p;
    int (*register_cmd)(void *p, char *cmd_name, itf_command_t *cmd);
    int (*call)(void *p, int argc, char **argv);
    int (*set_stdout)(void *p, itf_writer_t *writer);
} itf_commander_t;

#endif