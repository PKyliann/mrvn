/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** comparison.c
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

int contain_dollar(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '$')
            return 1;
    return 0;
}

int check_dquotes(char *str, global_t *sh)
{
    for (int x = 0; str[x] != '\0'; x++)
        if (str[x] == '"')
            return 1;
    return 0;
}
