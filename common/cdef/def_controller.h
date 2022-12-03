#ifndef __DEF_CONTROLLER_H__
#define __DEF_CONTROLLER_H__

#include <stdint.h>
#include "def_command.h"
#include "def_io.h"

typedef struct
{
    void *p;
    int (*input)(void *p, int length, char *buf);
    int (*set_stdout)(void *p, itf_writer_t *writer);
} itf_controller_t;

#endif