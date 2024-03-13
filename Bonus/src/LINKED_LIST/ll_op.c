/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

void delete (int pos, llenv_s **env)
{
    llenv_s *temp = (*env);
    int i;
    if (pos == 0) {
        (*env) = (*env)->next;
        temp->next = NULL;
        free(temp);
    } else {
        for (i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        llenv_s *del = temp->next;
        temp->next = temp->next->next;
        del->next = NULL;
        free(del);
    }
}

void replace_ll(llenv_s **env, char *var)
{
    if (var == NULL) {
        return;
    }
    llenv_s *head = (*env);
    var = my_concat(var, "\0");
    int len_var = my_strlen_var(var);
    for (; head; head = head->next) {
        if (my_strncmp(head->data, var, len_var) == 0) {
            head->data = my_strdup(var);
            break;
        }
    }
}

int l_env_ll(llenv_s **env)
{
    int i;
    llenv_s *head = (*env);
    for (i = 0; head; head = head->next, i++);
    return i;
}

char **my_ll_to_array(llenv_s **env)
{
    int i = 0;
    llenv_s *temp = (*env);
    int len = l_env_ll(env);
    char **array = NULL;
    array = malloc(sizeof(char *) * (len + 1));
    for (; temp != NULL; temp = temp->next, i++)
        array[i] = my_strdup(temp->data);
    array[i] = NULL;
    return array;
}
