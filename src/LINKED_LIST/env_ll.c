/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

void init(llenv_s **env, char *data)
{
    llenv_s *new = malloc(sizeof(llenv_s));
    new->data = data;
    new->next = NULL;
    (*env) = new;
}

void push_back(llenv_s **env, char *data)
{
    if ((*env) == NULL) {
        init(env, data);
        return;
    }
    llenv_s *new = malloc(sizeof(llenv_s));
    llenv_s *last = (*env);
    new->data = data;
    new->next = NULL;
    for (;last->next != NULL; last = last->next);
    last->next = new;
}

int l_env(char **env)
{
    int i = 0;
    for (; env[i] != NULL; i++);
    return i;
}

void create_ll(llenv_s **env_ll, char **env)
{
    int len_env = l_env(env);
    for (int i = 0; i < len_env; i++)
        push_back(*(&env_ll), env[i]);
}
