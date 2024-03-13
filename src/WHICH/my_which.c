/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** my_which.c
*/

#include "../../include/minishell.h"

int check_first_exist(char *path, char *command, int *found)
{
    if (access(path, F_OK | X_OK) == 0) {
        my_printf("%s\n", path);
        return 1;
    }
    return 0;
}

static int check_arguments(global_t *sh)
{
    if (sh->shell_array[1] == NULL) {
        my_printf("%s: Too few arguments.\n", sh->shell_array[0]);
        return 84;
    }
    return 0;
}

int is_builtin_which(char *command, int *tmp)
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
            my_printf("%s: shell built-in command.\n", command);
            *tmp += 1;
            return 1;
        }
    return 0;
}

static int process_command(global_t *sh, int i)
{
    char *command = sh->shell_array[i];
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *token = strtok(path_copy, ":");
    int found = 0;
    int tmp = 0;
    while (token != NULL && !found) {
        if (is_builtin_which(command, &tmp) == 1)
            break;
        char path_buffer[50];
        snprintf(path_buffer, sizeof(path_buffer), "%s/%s", token, command);
        found = check_first_exist(path_buffer, command, &found);
        token = strtok(NULL, ":");
    }
    if (found == 0)
        my_printf("%s: Command not found.\n", command);
    free(path_copy);
    return found;
}

int my_which(global_t *sh)
{
    int check_arg = check_arguments(sh);
    if (check_arg != 0)
        return check_arg;
    for (int i = 1; sh->shell_array[i] != NULL; i++) {
        process_command(sh, i);
    }
    return 0;
}
