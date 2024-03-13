/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

int check_len(char **shell_array, llenv_s **env)
{
    int len = 0;
    for (; shell_array[len] != NULL; len++);
    if (len == 1) {
        display_env(shell_array, env);
        return 0;
    }
    return 1;
}

int error_handling(int res)
{
    if (res == -1) {
        return 84;
    } else {
        write(2, "setenv: Variable name must contain"
        " alphanumeric characters.\n", 60);
        return 84;
    }
}
