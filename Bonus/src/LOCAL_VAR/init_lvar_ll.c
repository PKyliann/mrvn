/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** init_lvar_ll.c
*/

#include "../../include/minishell.h"
#include "../../my_printf//my/include/my_printf.h"

int is_alnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 65 || str[i] > 90 )
            && (str[i] < 97 || str[i] > 122)
            && (str[i] < 48 || str[i] > 57 )) {
            return 1;
        }
    }
    return 0;
}

void print_vars(lvar_t *vars)
{
    lvar_t *cur_var = vars;
    while (cur_var != NULL) {
        my_printf("%s\t%s\n", cur_var->name, cur_var->value);
        cur_var = cur_var->next;
    }
}

int err_var(char *name)
{
    if (!char_isalpha(name[0])){
        write(2, "set: Variable name must start with a letter.\n", 45);
        return 1;
    }
    if (is_alnum(name) == 1){
        write(2, "set: Variable name must contain"
        " alphanumeric characters.\n", 57);
        return 1;
    }
    return 0;
}

void init_lvarll(lvar_t **vars_ll, char *name, char *value)
{
    if (err_var(name) == 1){
        return;
    }
    lvar_t *new_node = malloc(sizeof(lvar_t));
    new_node->name = name;
    new_node->value = value;
    new_node->next = NULL;
    (*vars_ll) = new_node;
}
