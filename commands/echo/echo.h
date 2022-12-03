#ifndef __ECHO_H__
#define __ECHO_H__

#include "cdef/def_command.h"

typedef struct echo
{
    itf_command_t cmd;
    char *name;
}echo_cmd_t;

void echo_cmd_init(echo_cmd_t *p);


#endif