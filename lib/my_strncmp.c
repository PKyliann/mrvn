/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** task 07 day 6
*/

#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (s1 == NULL || s2 == NULL)
        return 84;
    int i = 0;
    for (; i < n; i++) {
        if (s1[i] != s2[i])
            return 1;
    }
    return 0;
}
