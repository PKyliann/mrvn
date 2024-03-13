/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell2-camille.ricardon
** File description:
** my_parse.c
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

char *add_space(char *str, int i)
{
    int len = my_strlen(str);
    int space_pos = 0;
    if (i == 1 || i == 3)
        space_pos = 1;
    else
        space_pos = 2;
    char *dest = malloc(sizeof(char) * (len + 1));
    for (int x = 0, a = 0; x < (len + 1); x++) {
        if (x != space_pos) {
            dest[x] = str[a]; a++;
        } else
            dest[x] = ' ';
    }
    dest[len + 1] = '\0';
    return dest;
}

int cond(char *result, int i, char **command)
{
    if (result != NULL) {
        result = add_space(result, i);
        if (strncmp(result, command[i], my_strlen(command[i])) == 0)
            return i;
    }
    return -1;
}

int comp_redir(char *shell_line)
{
    int i;
    char *command[4] = {"<<", "<", ">>", ">"};
    for (i = 0; i < 4; i++) {
        char *result = strstr(shell_line, command[i]);
        if (cond(result, i, command) != -1)
            return i;
    }
    return -1;
}

int parse(global_t *sh)
{
    int len_arr = len_array(sh->shell_array);
    if (len_arr == 1)
        return -1;
    if (strncmp(sh->shell_array[0], "<", 1) == 0) {
        sh->shell_array = puzzle(sh->shell_array);
    }
    int (*fc_ptr[4])(global_t *sh) = { &double_lr, \
    &simple_lr, &double_rr, &simple_rr };
    int a = -1;
    for (int i = 0; sh->shell_array[i] != NULL; i++) {
        a = comp_redir(sh->shell_array[i]);
        if (a == 2 || a == 3)
            sh->shell_array = puzzle_redir(sh->shell_array);
        if (a != -1)
            return (fc_ptr[a])(sh);
    }
    return 0;
}
