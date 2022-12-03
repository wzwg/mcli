#ifndef __COMMANDER_ITF_H__
#define __COMMANDER_ITF_H__

#include "cdef/def_commander.h"
#include "cdef/def_io.h"

itf_commander_t *commander_itf_new(itf_writer_t *outobj);
int commander_itf_deinit(itf_commander_t *p);
/**
 * A solution for the problem to staticly create data
 code begin:
    #include <stdint.h>
    #include "commander.h"
    typedef uint8_t itf_commander_default_buf_t[sizeof(commander_t)];

*/

#endif // __COMMANDER_ITF_H__