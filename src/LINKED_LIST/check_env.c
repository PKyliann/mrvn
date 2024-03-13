/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

char *create_var(char *value)
{
    int len = my_strlen(value);
    char *var = malloc(sizeof(char) * (len + 1));
    var = my_strcpy(var, value);
    return var;
}

void init_ll(llenv_s **env)
{
    llenv_s *new = malloc(sizeof(llenv_s));
    new->data = "PATH=/usr/bin:/bin:/usr/local/bin";
    new->next = NULL;
    (*env) = new;
}

void add_pwd(llenv_s **env)
{
    char *pwd = malloc(sizeof(char*) + 1);
    pwd = getcwd(NULL, 0);
    pwd = create_pwd_var(pwd, "PWD ");
    char **pwd_array = my_str_to_words_array(pwd);
    my_setenv(pwd_array, env);
}

void add_path(llenv_s **env)
{
    char *path = malloc(sizeof(char*) + 1);
    path = "/usr/bin:/bin:/usr/local/bin";
    path = create_pwd_var(path, "PATH ");
    char **path_array = my_path_array(path);
    my_setenv(path_array, env);
}

void check(llenv_s **env)
{
    if ((*env) == NULL)
        init_ll(env);
    int pwd_v = 0; int path_v = 0;
    llenv_s *head = (*env);
    for (; head; head = head->next) {
        if (my_strncmp("PWD=", head->data, 4) == 0)
            pwd_v = 1;
        if (my_strncmp("PATH=", head->data, 5) == 0)
            path_v = 1;
    }
    if (!pwd_v)
        add_pwd(env);
    if (!path_v)
        add_path(env);
}
