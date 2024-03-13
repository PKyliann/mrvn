/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"
#include "../../include/lib.h"

char *find_path(llenv_s **env)
{
    llenv_s *head = (*env);
    char *str = "PATH=";
    char *path = NULL;
    for (; head; head = head->next)
        if (my_strncmp(head->data, str, 5) == 0)
            path = my_strdup(head->data);
    return path;
}

char **parse_path(llenv_s **env)
{
    char *path = find_path(env);
    char **path_array = my_path_to_array(path);
    return path_array;
}

int is_real(char *path)
{
    if (access(path, F_OK) == 0) {
        if (access(path, X_OK) == 0)
            return 0;
        else
            return 1;
    }
    return 1;
}

char *check_path(char **path_array, char *shell_line)
{
    char *path = NULL;
    for (int i = 1; path_array[i] != NULL; i++) {
        path = make_path(shell_line, path_array[i]);
        if (access(path, F_OK | X_OK) == 0) {
            return path;
        }
    }
    return NULL;
}

char *create_path(char **shell_array, llenv_s *env_ll)
{
    llenv_s *head = env_ll;
    char *path = NULL;
    char **path_array = NULL;
    if (start_w_slash(shell_array[0])) {
        path = my_strdup(shell_array[0]);
        if (access(path, F_OK) == 0) {
            return path;
        }
        return NULL;
    } else {
        path_array = parse_path(&head);
        path = check_path(path_array, shell_array[0]);
        return path;
    }
}
