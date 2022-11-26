#include <stdio.h>
#include <time.h>

#include "commander.h"



int main(int argc, char **argv)
{
    commander_t cmder;

    commander_init(&cmder, 0);

    commander_call(&cmder, 1, "echo");

    return 0;
}
