/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell2-camille.ricardon
** File description:
** create_triple_array.c
*/

#include "../include/minishell.h"

void *my_realloc(void *ptr, int len)
{
    void *new_ptr = malloc(sizeof(char) + len);
    if (new_ptr == NULL)
        return NULL;
    char *src = (char*) ptr;
    char *dst = (char*) new_ptr;
    for (int i = 0; i < len; i++)
        dst[i] = src[i];
    free(ptr);
    return new_ptr;
}

char ***assemble_command(char **shell_array)
{
    char *buff = malloc(sizeof(char)); int len_buff = 0; int len_arr = 0;
    for (int i = 0; shell_array[i] != NULL; i++) {
        len_buff = my_strlen(buff);
        shell_array[i] = my_strcat(shell_array[i], " ");
        len_arr = my_strlen(shell_array[i]);
        buff = my_realloc(buff, (len_buff + len_arr + 1));
        memset(buff + len_buff, 0, len_arr + 1);
        buff = my_strcat(buff, shell_array[i]);
    }
    char **command = my_str_to_str_parray(buff);
    char ***commands = malloc(sizeof(char **) * (2 + 1));
    commands[0] = my_str_to_words_array(command[0]);
    commands[1] = my_str_to_words_array(command[1]);
    commands[2] = NULL;
    return commands;
}

char ***assemble_lines(char **shell_array)
{
    int len; int x;
    for (len = 0; shell_array[len] != NULL; len++);
    char ***lines = malloc(sizeof(char **) * (len + 1));
    for (x = 0; shell_array[x] != NULL; x++)
        lines[x] = my_str_to_words_array(shell_array[x]);
    lines[x] = NULL;
    return lines;
}

char ***assemble_commands(char **shell_array, int x)
{
    if (shell_array == NULL)
        return NULL;
    char **(*fc_ptr[2])(char *str) = { &my_str_to_str_rarray, \
    &my_str_to_str_drarray };
    char *buff = malloc(sizeof(char) * 100); int len_buff = 0; int len_arr = 0;
    for (int i = 0; shell_array[i] != NULL; i++) {
        if (i != 0)
            len_buff = my_strlen(buff);
        shell_array[i] = my_concat(shell_array[i], " ");
        len_arr = my_strlen(shell_array[i]);
        buff = realloc(buff, (len_buff + len_arr + 1));
        memset(buff + len_buff, 0, len_arr + 1);
        buff = my_concat(buff, shell_array[i]);
    }
    char **command = (*fc_ptr[x])(buff);
    char ***commands = malloc(sizeof(char **) * (2 + 1));
    commands[0] = my_str_to_words_array(command[0]);
    commands[1] = my_str_to_words_array(command[1]);
    commands[2] = NULL;
    return commands;
}
