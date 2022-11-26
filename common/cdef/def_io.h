#ifndef __DEF_IO_H__
#define __DEF_IO_H__

#include <stdint.h>

typedef int (*writer_t)(void *p, uint8_t *buf, int length);

typedef struct {
    void *p;
    writer_t writer;
}itf_writer_t;

#endif 