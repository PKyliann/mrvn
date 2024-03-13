/*
** EPITECH PROJECT, 2023
** my_exit.c
** File description:
** mini-shell
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

int my_exit(char **shell_array, llenv_s **env_ll)
{
    if (!env_ll)
        return 1;
    int status = 0;
    if (shell_array[1] != NULL) {
        status = my_getnbr(shell_array[1]);
    }
    global_t *sh = getstruct();
    end_prog(sh);
    exit(status);
}
