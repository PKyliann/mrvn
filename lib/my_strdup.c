/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** 1st task day 8
*/

#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

int my_strlen(char const *src);

char *my_strdup(char const *src)
{
    char *dest;
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
