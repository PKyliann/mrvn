/*
** EPITECH PROJECT, 2022
** my_strccat.c
** File description:
** minishell 2
*/

#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int k = my_strlen(dest);
    int p = my_strlen(src);
    char *result = malloc(sizeof(char) * (k + p) + 1);
    while (dest[i] != '\0') {
        result[i] = dest[i];
        i++;
    }
    int o = 0;
    while (src[o] != '\0') {
        result[i] = src[o];
        o++;
        i++;
    }
    result[i] = '\0';
    return result;
}
