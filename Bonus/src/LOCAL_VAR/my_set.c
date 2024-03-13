/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** my_set.c
*/

#include "../../include/minishell.h"
#include "../../my_printf//my/include/my_printf.h"

void push_var(lvar_t **vars_ll, char *name, char *value)
{
    lvar_t *current = *vars_ll;
    while (current != NULL){
        if (my_strcmp(current->name, name) == 0){
            current->value = value;
            return;
        }
        current = current->next;
    }
    if ((*vars_ll) == NULL) {
        init_lvarll(vars_ll, name, value);
        return;
    }
    lvar_t *new_node = malloc(sizeof(lvar_t));
    lvar_t *last = (*vars_ll);
    new_node->name = name;
    new_node->value = value;
    new_node->next = NULL;
    for (;last->next; last = last->next);
    last->next = new_node;
}

char *get_name(char *command)
{
    int len = 0; int i = 0;
    for (; command[len] != '='; len++);
    char *dest = malloc(sizeof(char) * (len + 1));
    for (; i < len; i++)
        dest[i] = command[i];
    dest[i] = '\0';
    return dest;
}

void set(char *command, lvar_t **vars_ll)
{
    char *buff = strstr(command, "=");
    if (buff == NULL) {
        push_var(vars_ll, command, "");
    } else {
        char *value = &buff[1];
        char *name = get_name(command);
        push_var(vars_ll, name, value);
    }
}

int my_set(global_t *sh)
{
    if (len_array(sh->shell_array) == 1) {
        print_vars(*sh->vars_ll);
        return 0;
    }
    for (int x = 1; sh->shell_array[x]; x++) {
        set(sh->shell_array[x], sh->vars_ll);
    }
    return 0;
}
