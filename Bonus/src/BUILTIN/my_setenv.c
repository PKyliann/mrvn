/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

int find_var(llenv_s **env, char *str)
{
    char *var = my_concat(str, "=");
    int len_var = my_strlen(var);
    for (; (*env); (*env) = (*env)->next) {
        if (my_strncmp((*env)->data, var, len_var) == 0) {
            return 1;
        }
    }
    return 0;
}

int check_param(char **shell_array)
{
    int len;
    for (len = 0; shell_array[len] != NULL; len++);
    if (len != 3)
        return 84;
    return 0;
}

int my_strlen_var(char *str)
{
    int len = 0;
    for (; str[len] != '='; len++);
    return len;
}

int my_setenv(char **shell_array, llenv_s **env_ll)
{
    char *var = NULL; int function = 0; llenv_s *head = (*env_ll);
    if (check_len(shell_array, env_ll) == 0)
        return 0;
    int res = contain_equaliser(shell_array);
    function = find_var(&head, shell_array[1]);
    if (res == 1 || res == 84 || res == -1)
        return error_handling(res);
    shell_array[1] = my_concat(shell_array[1], "=");
    if (shell_array[2] != NULL)
        var = my_concat(shell_array[1], shell_array[2]);
    else
        var = shell_array[1];
    if (function == 1) {
        replace_ll(env_ll, var);
        return 0;
    } else {
        push_back(env_ll, var);
        return 0;
    }
}
