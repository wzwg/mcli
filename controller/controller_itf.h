#ifndef __CONTROLLER_ITF_H__
#define __CONTROLLER_ITF_H__

#include "cdef/def_controller.h"
#include "cdef/def_commander.h"

itf_controller_t *controller_itf_new(itf_commander_t *cmder, itf_writer_t *writer);

#endif