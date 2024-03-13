/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

int command_error_pipes(char *path)
{
    global_t *sh = getstruct();
    if (check_alias(sh) != -1)
        return 0;
    if (comp(path) != -1)
        return 0;
    my_printf("%s: Command not found.\n", path);
    exit(-1);
}

void potat(global_t *sh, int prev_pipe, int next_pipe, int i)
{
    if (create_path(sh->commands[i], *sh->env_ll) == NULL
        && strncmp(sh->commands[i][0], "<", 1) != 0)
        command_error_pipes(sh->commands[i][0]);
    if (i != 0) {
        dup2(prev_pipe, STDIN_FILENO);
        close(prev_pipe);
    }
    if (sh->commands[i + 1] != NULL) {
        dup2(next_pipe, STDOUT_FILENO);
        close(next_pipe);
    }
    sh->shell_array = sh->commands[i];
    hub(sh);
    exit(EXIT_SUCCESS);
}

void pipe_loop(global_t *sh)
{
    int i; int fd[2]; int prev_pipe = 0;
    for (i = 0; sh->commands[i] != NULL; i++) {
        pipe(fd);
        pid_t pid = fork();
        if (pid == 0)
            potat(sh, prev_pipe, fd[1], i);
        if (i != 0)
            close(prev_pipe);
        close(fd[1]);
        prev_pipe = fd[0];
    }
    close(prev_pipe);
}

void pipe_function(global_t *sh)
{
    char ***commands = assemble_commandss(sh->shell_array);
    sh->commands = commands;
    pipe_loop(sh);
    while (wait(NULL) > 0);
}

int my_pipe(global_t *sh)
{
    if (len_array(sh->shell_array) == 1
        && strcmp(sh->shell_array[0], "|") == 0) {
        my_printf("Invalid null command.\n");
        return 1;
    }
    if (len_array(sh->shell_array) == 2) {
        my_printf("Invalid null command.\n");
        return 1;
    }
    pipe_function(sh);
    return 0;
}
