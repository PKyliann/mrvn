/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell2-camille.ricardon
** File description:
** my_parsing.c
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

char ***assemble_commandss(char **shell_array)
{
    if (shell_array == NULL)
        return NULL;
    int i = 0;
    char *buff = NULL;
    int len_buff = 0; int len_arr = 0;
    for (i = 0; shell_array[i] != NULL; i++) {
        len_buff = (buff != NULL) ? strlen(buff) : 0;
        shell_array[i] = my_concat(shell_array[i], " ");
        len_arr = strlen(shell_array[i]);
        buff = realloc(buff, (len_buff + len_arr + 1));
        memset(buff + len_buff, 0, len_arr + 1);
        buff = my_concat(buff, shell_array[i]);
    }
    char **command = my_str_to_str_parray(buff);
    char ***commands = calloc((i + 1), sizeof(char **));
    int x = 0;
    for (x = 0; command[x] != NULL; x++)
        commands[x] = my_str_to_words_array(command[x]);
    commands[x] = NULL;
    return commands;
}
