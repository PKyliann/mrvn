/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** parse_alias.c
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

int check_alias(global_t *sh)
{
    alias_t *tmp = *sh->alias;
    char *var = sh->shell_array[0];
    var = my_concat(var, " ");
    for (int cpt = 0; tmp; tmp = tmp->next, cpt++)
        if (strncmp(tmp->name, var, strlen(tmp->name)) == 0) {
            return cpt;
        }
    return -1;
}

int check_alias_var(char *val, global_t *sh)
{
    alias_t *tmp = *sh->alias;
    char *var = val;
    var = my_concat(var, " ");
    for (int cpt = 0; tmp; tmp = tmp->next, cpt++)
        if (strncmp(tmp->name, var, strlen(tmp->name)) == 0) {
            return cpt;
        }
    return -1;
}

void fill_alias_command(global_t *sh, int pos)
{
    alias_t *tmp = *sh->alias;
    for (int cpt = 0; tmp; tmp = tmp->next, cpt++) {
        if (cpt == pos && len_array(sh->shell_array) == 1) {
            sh->shell_array = my_str_to_words_array(tmp->data);
            break;
        }
        if (cpt == pos) {
            sh->shell_array = my_array_concat(tmp->data, sh->shell_array);
            break;
        }
    }
}

char *replace_alias_str(global_t *sh, int pos)
{
    alias_t *tmp = *sh->alias;
    char *var = sh->shell_array[pos];
    var = my_concat(var, " ");
    for (int cpt = 0; tmp; tmp = tmp->next, cpt++) {
        if (strncmp(tmp->name, var, strlen(tmp->name)) == 0) {
            return tmp->data;
        }
    }
    return NULL;
}
