/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** my_bang.c
*/

#include "../../include/minishell.h"

char *bang_number(history_t *curr, char *res, int *found)
{
    char index_str[20];
    while (strcmp(res, index_str) != 0 && curr->prev != NULL) {
        curr = curr->prev;
        sprintf(index_str, "%d", curr->index);
        if (strcmp(res, index_str) == 0) {
            res = strdup((char *) curr->data);
            my_printf("%s\n", (char *) curr->data);
            *found += 1;
            break;
        }
    }
    return res;
}

char *bang_bang(char *res, history_t *curr, int *found)
{
    res = strdup((char *) curr->prev->data);
    my_printf("%s\n", (char *) curr->prev->data);
    *found += 1;
    return res;
}

char *bang_command(char *res, history_t *curr, int *found)
{
    res = strdup((char *) curr->data);
    my_printf("%s\n", (char *) curr->data);
    *found += 1;
    return res;
}

int find_or_not(global_t *sh, history_t *curr, char *res, int found)
{
    if (found != 0) {
        sh->shell_array[0] = res;
        for (; curr->next; curr = curr->next);
        curr->data = sh->shell_array[0];
    } else {
        my_printf("%s: Event not found.\n", res);
        return 84;
    }
    return 0;
}
