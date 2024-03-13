/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** my_unset.c
*/

#include "../../include/minishell.h"
#include "../../my_printf//my/include/my_printf.h"

void if_condition(lvar_t **env, lvar_t *prev, lvar_t *curr)
{
    if (prev == NULL) {
        (*env) = (*env)->next;
    } else {
        prev->next = curr->next;
    }
}

lvar_t **del(lvar_t **head, char *name, char **pot)
{
    int i; int len = 0;
    lvar_t *prev; lvar_t *curr; lvar_t *temp;
    for (i = 1; pot[i] != NULL; i++) {
        len = my_strlen(pot[i]);
        prev = NULL; curr = *head;
        if (curr != NULL && strncmp(curr->name, pot[i], len) == 0) {
            *head = curr->next;
            free(curr);
            continue;
        }
        while (curr != NULL && strncmp(curr->name, pot[i], len) != 0) {
            prev = curr;
            curr = curr->next;
        }
        if (curr != NULL) {
            prev->next = curr->next;
            free(curr);
        }
    }
    return head;
}

int my_unset(global_t *sh)
{
    int len;
    for (len = 0; sh->shell_array[len] != NULL; len++);
    for (int i = 1; i < len; i++) {
        sh->vars_ll = del(sh->vars_ll, sh->shell_array[0], sh->shell_array);
    }
    return 0;
}
