#ifndef __DEF_COMMAND_H__
#define __DEF_COMMAND_H__

#include "def_io.h"

// definition of command
typedef void (*command_entry_t)(void *p, int argc, const char **argv, itf_writer_t *out);

// definition of command internal storage model
typedef struct {
    void *p;
    command_entry_t entry;
}itf_command_t;



#endif 