/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** my_sighandler.c
*/

#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

void end_prog(global_t *sh)
{
    tcsetattr(STDIN_FILENO, TCSANOW, sh->old_tio);
    add_to_history_file(sh, sh->env_ll);
    if (sh->shell_array != NULL)
        my_free_array(sh->shell_array);
    if (sh->commands != NULL)
        my_free(sh->commands);
    save_alias_file(sh);
    llenv_s *tmp = *sh->env_ll;
    while (tmp != NULL) {
        llenv_s *next = (tmp)->next;
        free(tmp);
        tmp = next;
    }
    alias_t *tmp_bis = *sh->alias;
    while (tmp_bis != NULL) {
        alias_t *next = (tmp_bis)->next;
        free(tmp_bis);
        tmp_bis = next;
    }
}

void handle_signal(int signal)
{
    if (signal == SIGINT) {
        global_t *sh = getstruct();
        end_prog(sh);
        exit(0);
    }
}
