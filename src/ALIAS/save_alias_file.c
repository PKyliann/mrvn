/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** load_charge_alias_file.c
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

void write_in_file(global_t *sh, FILE *file)
{
    alias_t *tmp = *sh->alias;
    for (; tmp; tmp = tmp->next)
        fprintf(file, "%s;%s\n", tmp->name, tmp->data);
    fclose(file);
}

void save_alias_file(global_t *sh)
{
    char *filepath = NULL;
    llenv_s *head = *sh->env_ll;
    for (; head; head = head->next) {
        if (strncmp(head->data, "ALIASPOTAT=", 11) == 0) {
            filepath = &head->data[11];
            break;
        }
    }
    if (filepath) {
        FILE *file = fopen(filepath, "w+");
        if (file) {
            write_in_file(sh, file);
        } else {
            return;
        }
    } else {
        return;
    }
}
