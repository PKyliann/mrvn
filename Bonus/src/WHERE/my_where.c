/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** my_where.c
*/

#include "../../include/minishell.h"

void check_if_exist(char *path)
{
    if (access(path, F_OK | X_OK) == 0)
        my_printf("%s\n", path);
}

int is_builtin(char *command, int *tmp)
{
    char *builtin[] = { ":", "@", "alias", "alloc", "bg", "bindkey", "break",
    "breaksw", "builtins", "case", "cd", "chdir", "complete", "continue",
    "default", "dirs", "echo", "echotc", "else", "end", "endif", "endsw",
    "eval", "exec", "exit", "fg", "filetest", "foreach", "glob", "goto",
    "hashstat", "history", "hup", "if", "jobs", "kill", "limit", "log",
    "login", "logout", "ls-F", "nice", "nohup", "notify", "onintr", "popd",
    "printenv", "pushd", "rehash", "repeat", "sched", "set", "setenv",
    "settc", "setty", "shift", "source", "stop", "suspend", "switch",
    "telltc", "termname", "time", "umask", "unalias", "uncomplete",
    "unhash", "unlimit", "unset", "unsetenv", "wait", "where", "which",
    "while", NULL };
    for (int i = 0; builtin[i] != NULL; i++)
        if (strcmp(command, builtin[i]) == 0) {
            my_printf("%s is a shell built-in\n", command);
            *tmp += 1;
            return 1;
        }
    return 0;
}

int follow(int *tmp, global_t *sh, int i)
{
    if (*tmp == 0)
        is_builtin(sh->shell_array[i], tmp);
    return 0;
}

int my_where(global_t *sh)
{
    if (sh->shell_array[1] == NULL) {
        printf("%s: Too few arguments.\n", sh->shell_array[0]);
        return 84;
    } int tmp = 0;
    for (int i = 1; sh->shell_array[i] != NULL; i++) {
        char *command = sh->shell_array[i];
        char *path = getenv("PATH");
        char *path_copy = strdup(path);
        char *token = strtok(path_copy, ":");
        while (token != NULL) {
            follow(&tmp, sh, i);
            char path_buffer[50];
            snprintf(path_buffer, sizeof(path_buffer), "%s/%s", token, command);
            check_if_exist(path_buffer);
            token = strtok(NULL, ":");
        }
        free(path_copy);
    }
    return 0;
}
