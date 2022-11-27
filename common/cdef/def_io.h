#ifndef __DEF_IO_H__
#define __DEF_IO_H__

#include <stdint.h>

typedef int (*write_t)(void *p, uint8_t *buf, int length);

typedef struct {
    void *p;
    write_t write;
}itf_writer_t;

#endif 