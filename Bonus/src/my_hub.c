/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** my_hub.c
*/

#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

int comp(char *shell_line)
{
    int i;
    char *command[6] = {"env", "unsetenv", "setenv", "exit", "cd"};
    for ( i = 0; command[i] != NULL ; i++)
        if (my_strcmp(command[i], shell_line) == 0)
            return i;
    return -1;
}

int cmp(char *shell_line)
{
    int i;
    char *command[10] = {"alias", "unalias", "repeat", "where", "which", \
    "set", "unset", "history", "!"};
    for ( i = 0; command[i] != NULL ; i++)
        if (my_strcmp(command[i], shell_line) == 0)
            return i;
    return -1;
}

void exec_builtin(global_t *sh)
{
    int ali = check_alias(sh);
    int ref = cmp(sh->shell_array[0]);
    int (*fc_ptr[5])(char **shell_array, llenv_s **env_ll) = {&display_env, \
    &my_unsetenv, &my_setenv, &my_exit, &cd_command};
    int (*fc_ptr_42sh[10])(global_t *sh) = {&my_alias, &my_unalias, \
    &my_repeat, &my_where, &my_which, &my_set, &my_unset, &my_history, &bang};
    int res = comp(sh->shell_array[0]);
    if (ali != -1)
        fill_alias_command(sh, ali);
    if (res != -1)
        sh->status = (*fc_ptr[res])(sh->shell_array, sh->env_ll);
    else if (ref != -1)
        sh->status = (*fc_ptr_42sh[ref])(sh);
    else
        sh->status = forking(sh);
}

void parse_command(global_t *sh)
{
    int nb_pipes = is_pipe(sh->shell_array);
    int nb_op = is_operator(sh->shell_array);
    if (redif(sh->shell_array) == 1 && nb_pipes == 0) {
        parse(sh); return;
    }
    if (nb_op >= 1) {
        my_operator(sh);
        return;
    } else if (nb_pipes >= 1) {
        my_pipe(sh);
        return;
    } else {
        exec_builtin(sh);
    }
}

void hub(global_t *sh)
{
    int nb_op = is_operator(sh->shell_array);
    if (nb_op >= 1) {
        my_operator(sh);
    } else if (redif(sh->shell_array) == 1) {
        parse(sh);
    } else {
        exec_builtin(sh);
    }
}
