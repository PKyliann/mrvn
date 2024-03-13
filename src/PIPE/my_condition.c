/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell2-camille.ricardon
** File description:
** my_condition.c
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

int condition(char *shell_array)
{
    for (int j = 0; shell_array[j]; j++)
        if (shell_array[j] == '<' || shell_array[j] == '>')
            return 1;
    return 0;
}

int redif(char **shell_array)
{
    for (int i = 0; shell_array[i] != NULL; i++)
        if (condition(shell_array[i]) == 1)
            return 1;
    return 0;
}

int cpt_pipe(char *line, int cpt)
{
    for (int j = 0; line[j] != '\0'; j++)
        if (line[j] == '|')
            cpt++;
    return cpt;
}

int is_pipe(char **shell_array)
{
    int cpt = 0;
    for (int i = 0; shell_array[i] != NULL; i++)
        cpt = cpt_pipe(shell_array[i], cpt);
    return cpt;
}

int my_comp(char *line, char *ref)
{
    int len = my_strlen(ref);
    for (int i = 0; i < len ; i++)
        if (line[i] != ref[i])
            return 1;
    return 0;
}
