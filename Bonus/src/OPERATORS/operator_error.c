/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** op_error.c
*/

#include "../../include/minishell.h"

int and_error(global_t *sh)
{
    if (len_array(sh->shell_array) == 1
    && strstr("&&", sh->shell_array[0]) != NULL)
        return 84;
    if (sh->shell_array[2] == NULL
        && strstr("&&", sh->shell_array[0]) == NULL) {
        my_printf("Invalid null command.\n");
        return 84;
    }
    return 0;
}

int or_error(char **result)
{
    if ( len_array(result) < 2
    || (len_array(result) <= 2 && strcmp(result[1], " ") == 0)) {
        my_printf("Invalid null command.\n");
        return 84;
    }
    return 0;
}
