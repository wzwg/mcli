#include "default_command.h"
#include "echo/echo.h"
#include "util.h"

int register_builtin_commands(itf_commander_t *cmder)
{
    // todo
    echo_cmd_t *cmd = (echo_cmd_t *)malloc(sizeof(echo_cmd_t));
    echo_cmd_init(cmd);

    ITF_CALL(cmder, register_cmd, cmd->name, &cmd->cmd);

    return 0;
}