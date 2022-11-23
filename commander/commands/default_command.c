#include "default_command.h"
#include "echo/echo.h"

int register_builtin_commands(commander_t *cmder) 
{
    //todo
    echo_cmd_t *cmd = (echo_cmd_t *)malloc(sizeof(echo_cmd_t));
    echo_cmd_init(cmd);
    commander_register(cmder, cmd->name, &cmd->cmd);

    return 0;
}