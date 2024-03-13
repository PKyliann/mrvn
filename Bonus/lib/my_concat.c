/*
** EPITECH PROJECT, 2022
** concat_params.c
** File description:
** 2nd task day 8
*/

#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

char *concat_path(char *slash, char *shell_line)
{
    if (!slash || !shell_line)
        return NULL;
    if (shell_line == NULL)
        exit(84);
    int i = 1;
    int j = 0;
    int len = my_strlen(shell_line);
    char *path = malloc(sizeof(char) * (len + 2));
    path[0] = '/';
    for (; shell_line[j] != '\0'; i++, j++)
        path[i] = shell_line[j];
    path[i] = '\0';
    return path;
}

char *my_concat(const char *path, const char *str)
{
    if (path == NULL || str == NULL) {
        return NULL;
    }
    int path_len = strlen(path);
    int str_len = strlen(str);
    char *result = malloc(path_len + str_len + 1);
    if (result == NULL) {
        return NULL;
    }
    strcpy(result, path);
    strcat(result, str);
    return result;
}

char *make_path(char *line, char *path_var)
{
    char *shell_line = concat_path("/", line);
    char *path = my_concat(path_var, shell_line);
    return path;
}
