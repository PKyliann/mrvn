/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

int error(int argc, char **argv)
{
    (void) argv;
    if (argc != 1)
        return 84;
    return 0;
}

void linked_lists(llenv_s **env_ll, char **env)
{
    create_ll(env_ll, env);
    check(env_ll);
}

global_t *create_global_struct(llenv_s **env_ll, history_t **his, lvar_t **vars)
{
    global_t *sh = getstruct();
    sh->env_ll = env_ll; sh->history = his; sh->status = 0;
    sh->vars_ll = vars;
    return sh;
}

int main(int argc, char **argv, char **env)
{
    if (error(argc, argv) == 84)
        return 84;
    history_t *history = NULL; llenv_s *env_ll = NULL;
    alias_t *alias = NULL; lvar_t *vars_ll = NULL;
    linked_lists(&env_ll, env);
    create_history_var(env_ll);
    global_t *sh = create_global_struct(&env_ll, &history, &vars_ll);
    create_load_alias(sh, &alias);
    create_load_history(sh, &history);
    char *shell_line = NULL;
    sh_loop(shell_line, sh);
    end_prog(sh);
    return 0;
}
