/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** alias_ll.c
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

void init_alias(alias_t **alias, char *data, char *name)
{
    alias_t *new = malloc(sizeof(alias_t));
    new->name = name;
    new->data = data;
    new->next = NULL;
    (*alias) = new;
}

void push_back_alias(alias_t **alias, char *data, char *name)
{
    if ((*alias) == NULL) {
        init_alias(alias, data, name);
        return;
    }
    alias_t *new = malloc(sizeof(alias_t));
    alias_t *last = (*alias);
    new->name = name;
    new->data = data;
    new->next = NULL;
    for (;last->next != NULL; last = last->next);
    last->next = new;
}

void create_ll_alias(alias_t **alias, char **alias_data)
{
    for (int i = 0; alias_data[i] ; i++) {
        char **data = str_to_array_delim(alias_data[i], ";");
        push_back_alias(*(&alias), data[1], data[0]);
    }
}
