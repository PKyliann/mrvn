/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** my_free.c
*/

#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

void my_free_array(char **array)
{
    for (int x = 0; array[x]; x++)
        free(array[x]);
    free(array);
}

void my_free(char ***array)
{
    for (int x = 0; array[x]; x++) {
        for (int a = 0; array[x][a]; a++)
            free(array[x][a]);
        free(array[x]);
    }
    free(array);
}
