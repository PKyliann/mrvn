/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell2-camille.ricardon
** File description:
** my_str_to_str_drarray.c
*/

#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

static int nbr_lines(char *str)
{
    int i;
    int count = 1;
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n' || str[i] == '<' || str[i] == '>')
            count++;
    return count;
}

static int line_len(char *str, int nbr)
{
    int i;
    for (i = 1; str[nbr + i] != '\0' && str[nbr + i] != '\n'
                && str[nbr + i] != '<' && str[nbr + i] != '>'; i++);
    return i;
}

char **my_str_to_str_drarray(char *str)
{
    int a; int j; int i = 0;
    int nb_lines = nbr_lines(str);
    char **array = malloc(sizeof(char*) * (nb_lines + 1));
    for (a = 0; a < nb_lines; a++) {
        j = 0;
        array[a] = malloc(sizeof(char) * (line_len(str, i) + 1));
        for (; str[i] != '\0' && str[i] != '\n' && str[i] != '<'
        && str[i] != '>'; i++, j++) {
            array[a][j] = str[i];
        }
        i++; i++;
        array[a][j] = '\0';
    }
    array[a] = NULL;
    return array;
}
