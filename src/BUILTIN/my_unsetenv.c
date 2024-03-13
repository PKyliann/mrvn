/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

int comp_env(llenv_s **env_ll, char *shell_line)
{
    int cpt = 0;
    shell_line = my_concat(shell_line, "=");
    int len = my_strlen(shell_line);
    llenv_s *head = (*env_ll);
    for (; head; head = head->next, cpt++) {
        if (my_strncmp(shell_line, head->data, len) == 0) {
            return cpt;
        }
    }
    return -1;
}

int my_unsetenv(char **shell_array, llenv_s **env_ll)
{
    int len; int res = 0;
    for (len = 0; shell_array[len] != NULL; len++);
    for (int i = 1; i < len; i++) {
        res = comp_env(env_ll, shell_array[i]);
        if (res == -1)
            continue;
        delete(res, env_ll);
    }
    return 0;
}
