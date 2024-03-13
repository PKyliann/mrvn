/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** task 06 day 6
*/

#include "../include/minishell.h"

int my_strcmp(char *s1, char *s2)
{
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);
    if (len_s1 != len_s2)
        return 84;
    for (int j = 0; s1[j] != '\0'; j++)
        if (s1[j] != s2[j])
            return s2[j] - s1[j];
    return 0;
}

int my_strcmp_shell(char *s1, char *s2)
{
    for (int j = 0; s1[j] != '\0'; j++)
        if (s1[j] != s2[j])
            return s2[j] - s1[j];
    return 0;
}
