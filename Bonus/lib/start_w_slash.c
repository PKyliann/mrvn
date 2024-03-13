/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** start_w_slash.c
*/

#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

int start_w_slash(char const *shell_line)
{
    if (shell_line == NULL) {
        return 0;
    }
    if (my_strlen(shell_line) == 0) {
        return 0;
    }
    for (int i = 0; shell_line[i] != '\0'; i++)
        if (shell_line[i] == '/')
            return 1;
    return 0;
}
