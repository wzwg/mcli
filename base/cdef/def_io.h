#ifndef __DEF_IO_H__
#define __DEF_IO_H__

#include <stdint.h>

typedef int (*write_t)(void *p, const uint8_t *buf, int length);

typedef int (*write_string_t)(void *p, const char *buf);

typedef struct
{
    void *p;
    write_t write;
} itf_writer_t;

typedef struct
{
    void *p;
    write_string_t write;
} itf_string_writer_t;

#endif