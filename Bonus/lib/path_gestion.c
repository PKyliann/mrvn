/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

int ret_value(char *shell)
{
    for (int j = 0; shell[j] != '\0'; j++) {
        if (shell[j] == '=') {
            return 1;
        }
    }
    return 0;
}

int is_alpha_num(char c)
{
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90))
        return 1;
    if (c >= 97 && c <= 122)
        return 1;
    return 0;
}

int char_isalpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

int contain_equaliser(char **shell_array)
{
    if (char_isalpha(shell_array[1][0]) == 0) {
        write(2, "setenv: Variable name must "
        "begin with a letter.\n", 48);
        return -1;
    }
    for (int k = 0; shell_array[1][k] != '\0'; k++) {
        if (is_alpha_num(shell_array[1][k]) == 0) {
            return 84;
        }
    }

    for (int i = 0; shell_array[i] != NULL; i++) {
        if (ret_value(shell_array[i]) == 1)
            return i;
    }
    return 0;
}

char *concat_array(char **shell_array)
{
    char *temp;
    int i = 0; int j = 0;
    int k = 0; int len = 0;
    for (i = 1; shell_array[i] != NULL; i++)
        len += my_strlen(shell_array[i]);
    temp = malloc(len + 1);
    for (i = 1; shell_array[i] != NULL; i++) {
        for (j = 0; shell_array[i][j] != '\0'; j++, k++) {
            temp[k] = shell_array[i][j];
        }
    }
    k++;
    temp[k] = '\0';
    return temp;
}
