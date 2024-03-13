/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

int detect_parenthesis(char **shell_command)
{
    int nb_parenthesis = 0;
    for (int i = 0; shell_command[i] != NULL; i++) {
        for (int j = 0; shell_command[i][j] != '\0'; j++) {
            (shell_command[i][j] == '(') ? nb_parenthesis++ :
            (shell_command[i][j] == ')') ? nb_parenthesis-- : 0;
        }
    }
    if (nb_parenthesis > 0) {
        my_printf("Too many ('s.\n");
        return -1;
    } else if (nb_parenthesis < 0) {
        my_printf("Too many )'s.\n");
        return -1;
    }
    return 0;
}

char **remove_parentheses(char **shell_command)
{
    int i, j, k, len;
    char **without_parentheses;
    len = 0;
    for (i = 0; shell_command[i] != NULL; i++)
        for (j = 0; shell_command[i][j] != '\0'; j++) {
            shell_command[i][j] != '(' &&
            shell_command[i][j] != ')' ? len++ : len;
        }
    without_parentheses = malloc(sizeof(char *) * (i + 1));
    without_parentheses[i] = NULL;
    for (k = 0; k < i; k++) {
        without_parentheses[k] = malloc(sizeof(char) * (len + 1));
        without_parentheses[k][len] = '\0';
    }
    for (i = 0, k = 0; shell_command[i] != NULL; i++, k = 0)
        for (j = 0; shell_command[i][j] != '\0'; j++) {
            shell_command[i][j] != '(' && shell_command[i][j] != ')' ?
                    without_parentheses[i][k++] = shell_command[i][j] : k;
        }
    return without_parentheses;
}
