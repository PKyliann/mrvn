/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

int display_env(char **shell_array, llenv_s **env_ll)
{
    if (!shell_array)
        return 1;
    llenv_s *head = (*env_ll);
    for (; head; head = head->next)
        my_printf("%s\n", head->data);
    return 0;
}
