/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** display_array.c
*/

#include "../include/minishell.h"

void display_array(char **array)
{
    for (int x = 0; array[x]; x++)
        printf("array : %s\n", array[x]);
}
