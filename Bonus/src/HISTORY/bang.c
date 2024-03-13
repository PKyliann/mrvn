/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** bang.c
*/

#include "../../include/minishell.h"

static bool is_num(const char* chaine)
{
    for (int i = 0; chaine[i] != '\0'; i++) {
        if (chaine[i] < '0' || chaine[i] > '9')
            return false;
    }
    return true;
}

int bang(global_t *sh)
{
    char *res = &sh->shell_array[0][1];
    history_t *curr = *sh->history; int found = 0;
    for (; curr->next; curr = curr->next);
    while (curr != NULL) {
        if (is_num(res)) {
            res = bang_number(curr, res, &found); break;
        }
        if (strcmp(res, "!") == 0) {
            res = bang_bang(res, curr, &found); break;
        }
        if (strncmp(curr->data, res, my_strlen(res)) == 0) {
            res = bang_command(res, curr, &found); break;
        }
        curr = curr->prev;
    }
    if (find_or_not(sh, curr, res, found) == 84)
        return 84;
    hub(sh); return 0;
}
