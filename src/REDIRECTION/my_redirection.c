/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell2-camille.ricardon
** File description:
** my_redirection.c
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

int simple_rr(global_t *sh)
{
    char ***commands = a_c(sh->shell_array, 0); int file2; int status = 0;
    char *path = create_path(commands[0], (*sh->env_ll));  int res = 0;
    if (!path)
        return command_error(sh->shell_array[0]);
    char **env = my_ll_to_array(sh->env_ll); pid_t pid = fork();
    if (pid < 0)
        return -1;
    if (pid == 0) {
        int file = open(commands[1][0] ,O_CREAT | O_WRONLY, 0644);
        if (file == -1)
            return 0;
        file2 = dup2(file, STDOUT_FILENO); close(file);
        res = execve(path, commands[0], env);
        if (res == -1 && errno == ENOEXEC)
            return archi_error(path);
        if (res == -1 && errno == EACCES)
            return access_exec(path);
        close(file2);
    }
    waitpid(pid, &status, WUNTRACED); sig_handler(status); return 1;
}

int double_rr(global_t *sh)
{
    char ***commands = a_c(sh->shell_array, 1); int file2; int status = 0;
    char *path = create_path(commands[0], (*sh->env_ll)); int res = 0;
    if (!path)
        return command_error(sh->shell_array[0]);
    char **env = my_ll_to_array(sh->env_ll); pid_t pid = fork();
    if (pid < 0)
        return -1;
    if (pid == 0) {
        int file = open(commands[1][0] ,O_CREAT | O_WRONLY | O_APPEND, 0644);
        if (file == -1)
            return 0;
        file2 = dup2(file, STDOUT_FILENO); close(file);
        res = execve(path, commands[0], env);
        if (res == -1 && errno == ENOEXEC)
            return archi_error(path);
        if (res == -1 && errno == EACCES)
            return access_exec(path);
        close(file2);
    }
    waitpid(pid, &status, WUNTRACED); sig_handler(status); return 1;
}

int simple_lr(global_t *sh)
{
    char ***commands = a_c(sh->shell_array, 0); int file2; int status = 0;
    char *path = create_path(commands[0], (*sh->env_ll)); int res = 0;
    if (!path)
        return command_error(sh->shell_array[0]);
    char **env = my_ll_to_array(sh->env_ll); pid_t pid = fork();
    if (pid < 0)
        return -1;
    if (pid == 0) {
        int file = open(commands[1][0] ,O_RDONLY);
        if (file == -1)
            return 0;
        file2 = dup2(file, STDIN_FILENO); close(file);
        res = execve(path, commands[0], env);
        if (res == -1 && errno == ENOEXEC)
            return archi_error(path);
        if (res == -1 && errno == EACCES)
            return access_exec(path);
        close(file2);
    }
    waitpid(pid, &status, WUNTRACED); sig_handler(status); return 1;
}

int fork_pipe(char ***commands, char *res, llenv_s **env_ll)
{
    int fd[2];
    pipe(fd);
    char *path = create_path(commands[0], (*env_ll));
    char **env = my_ll_to_array(env_ll);
    int pid = fork();
    if (pid == 0) {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        execve(path, commands[0], env);
    } else {
        close(fd[0]);
        write(fd[1], res, my_strlen(res));
        close(fd[1]);
        waitpid(pid, NULL, 0);
    }
    return 0;
}

int double_lr(global_t *sh)
{
    char *line = NULL; size_t size = 0; char *res = malloc(sizeof(char));
    char ***commands = assemble_commands(sh->shell_array, 1);
    while (1) {
        my_printf("? ");
        getline(&line, &size, stdin);
        if (my_comp(line, commands[1][0]) == 0) {
            fork_pipe(commands, res, sh->env_ll);
            break;
        }
        res = my_strcat(res, line);
    }
    return 0;
}
