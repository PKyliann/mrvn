/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

int analyse_command(char **shell_array)
{
    int len = 0;
    for (; shell_array[len] != NULL; len++);
    if (len == 1)
        return 0;
    if (my_strcmp(shell_array[1], "-") == 0) {
        return 1;
    } else if (my_strcmp(shell_array[1], "~") == 0) {
        return 2;
    }
    return -1;
}

char *get_home(llenv_s **env)
{
    char *path = NULL;
    llenv_s *head = (*env);
    for (; head; head = head->next) {
        if (my_strncmp("HOME=", head->data, 5) == 0) {
            path = &head->data[5];
            return path;
        }
    }
    return NULL;
}

char *get_old_pwd(llenv_s **env)
{
    char *path = NULL;
    llenv_s *head = (*env);
    for (; head; head = head->next) {
        if (my_strncmp("OLDPWD=", head->data, 5) == 0) {
            path = &head->data[7];
            return path;
        }
    }
    return NULL;
}

char *create_pwd_var(char *pwd, char *name)
{
    int len = my_strlen(pwd);
    char *var = malloc(sizeof(char) * (len + 8));
    var = my_strcpy(var, "var ");
    var = my_concat(var, name);
    var = my_concat(var, pwd);
    return var;
}

int cd_command(char **shell_array, llenv_s **env_ll)
{
    char *path = shell_array[1];
    char *old_pwd = getcwd(NULL, 0);
    char *var = create_pwd_var(old_pwd, "OLDPWD ");
    char **pwd_array = my_str_to_words_array(var);
    int res = analyse_command(shell_array);
    if (res == 0 || res == 2)
        path = get_home(env_ll);
    if (res == 1)
        path = get_old_pwd(env_ll);
    int ret = chdir(path);
    if (ret == -1) {
        char *error = strerror(errno);
        fprintf(stderr, "%s: %s.\n", path, error); return 84;
    }
    my_setenv(pwd_array, env_ll); char *pwd = getcwd(NULL, 0);
    char *var_old = create_pwd_var(pwd, "PWD ");
    char **old_array = my_str_to_words_array(var_old);
    my_setenv(old_array, env_ll);
    return 0;
}
