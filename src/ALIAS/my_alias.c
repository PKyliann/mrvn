/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** my_alias.c
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

int display_alias(global_t *sh)
{
    alias_t *tmp = *sh->alias;
    for (; tmp; tmp = tmp->next)
        my_printf("%s%s\n", tmp->name, tmp->data);
    return 0;
}

int my_alias(global_t *sh)
{
    int len = len_array(sh->shell_array);
    if (len == 1) {
        display_alias(sh);
        return 0;
    }
    if (len < 3)
        return 0;
    char *var = sh->shell_array[1];
    var = my_concat(var, " ");
    char *value = my_concat_strings(&sh->shell_array[2]);
    alias_t *tmp = *sh->alias;
    for (; tmp; tmp = tmp->next) {
        if (strncmp(tmp->name, sh->shell_array[1], \
        strlen(sh->shell_array[1])) == 0) {
            tmp->data = value;
            return 0;
        }
    }
    push_back_alias(sh->alias, value, var);
    return 0;
}

int comp_alias(alias_t **alias, char *shell_line)
{
    int cpt = 0;
    int len = my_strlen(shell_line);
    alias_t *head = (*alias);
    for (; head; head = head->next, cpt++) {
        if (my_strncmp(shell_line, head->name, len) == 0) {
            return cpt;
        }
    }
    return -1;
}

void delete_alias(int pos, alias_t **alias)
{
    alias_t *temp = (*alias);
    int i;
    if (pos == 0) {
        (*alias) = (*alias)->next;
        temp->next = NULL;
        free(temp);
    } else {
        for (i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        alias_t *del = temp->next;
        temp->next = temp->next->next;
        del->next = NULL;
        free(del);
    }
}

int my_unalias(global_t *sh)
{
    if (len_array(sh->shell_array) == 1)
        return 0;
    int len; int res = 0;
    for (len = 0; sh->shell_array[len] != NULL; len++);
    for (int i = 1; i < len; i++) {
        res = comp_alias(sh->alias, sh->shell_array[i]);
        if (res == -1)
            continue;
        delete_alias(res, sh->alias);
    }
    return 0;
}
