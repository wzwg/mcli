#include <stdio.h>
#include <time.h>

#include "commander_itf.h"
#include "controller_itf.h"

#include "cdef/def_io.h"
#include "util.h"

static int write(void *p, const uint8_t *buf, int length)
{
    for (int i = 0; i < length; i++)
    {
        putchar(buf[i]);
    }

    return 0;
}

static itf_writer_t writer = {
    .p = &writer,
    .write = write,
};

int testCommander()
{
    itf_commander_t *cmder;

    cmder = commander_itf_new(&writer);

    char *cargv[] = {"echo", "test", "you are sou curted"};

    ITF_CALL(cmder, call, sizeof(cargv) / sizeof(*cargv), (const char **)cargv);

    return 0;
}

int main(int argc, char **argv)
{
    // testCommander();
    itf_commander_t *cmder = commander_itf_new(&writer);
    itf_controller_t *ctrler = controller_itf_new(cmder, &writer);

    char inputText[] = "echo hello world hahah";

    ITF_CALL(ctrler, input, sizeof(inputText), inputText);

    return 0;
}
