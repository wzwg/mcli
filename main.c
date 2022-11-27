#include <stdio.h>
#include <time.h>

#include "commander.h"
#include "cdef/def_io.h"

static int write(void *p, uint8_t *buf, int length)
{
    for (int i = 0; i < length; i++) {
        putchar(buf[i]);
    }
}

static itf_writer_t writer = {
    .p = &writer,
    .write = write,
};


int main(int argc, char **argv)
{
    commander_t cmder;

    commander_init(&cmder, &writer);

    char *cargv[] = {"echo", "test", "you are sou curted"};
    commander_call(&cmder, sizeof(cargv)/sizeof(*cargv), cargv);

    return 0;
}
