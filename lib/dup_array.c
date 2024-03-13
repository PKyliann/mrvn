/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** dup_array.c
*/

#include "../include/minishell.h"

char **dup_array(char **array)
{
    int len = 0;
    for (; array[len]; len++);
    char **tmp = malloc((len + 1) * sizeof(char *));
    for (int i = 0; i < len; i++) {
        tmp[i] = strdup(array[i]);
    }
    tmp[len] = NULL;
    return tmp;
}
