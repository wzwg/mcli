#ifndef __DEF_COMMAND_H__
#define __DEF_COMMAND_H__

// definition of command
typedef void (*command_entry_t)(void *p, const char **params, void *cstdout);

// definition of command internal storage model
typedef struct {
    void *p;
    command_entry_t entry;
}itf_command_t;



#endif 