/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** len_array.c
*/

#include "../include/minishell.h"

int len_array(char **array)
{
    int x = 0;
    for ( ; array[x] != NULL; x++);
    return x;
}

int len_triple(char ***triple)
{
    int x = 0;
    for (; triple[x] != NULL; x++);
    return x;
}
