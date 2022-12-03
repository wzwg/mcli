#ifndef __DEF_COMMAND_H__
#define __DEF_COMMAND_H__

#include "def_io.h"

// definition of command.
/*
 * argc: indicate the number of arguments
 * argv: arguments. the first argument is the command name
 */
typedef int (*command_entry_t)(void *p, int argc, const char **argv, itf_writer_t *outobj);

// definition of command internal storage model
typedef struct
{
    void *p;
    command_entry_t entry;
} itf_command_t;

#endif