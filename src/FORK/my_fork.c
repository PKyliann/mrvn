/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** my_fork.c
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

int forking(global_t *sh)
{
    char **argv = check_param_array(sh); int res = 0;
    if (argv == NULL)
        return 0;
    char *path = create_path(sh->shell_array, *sh->env_ll);
    if (!path)
        return command_error(sh->shell_array[0]);
    char **env = my_ll_to_array(sh->env_ll);
    pid_t pid = fork();
    if (pid < 0)
        return -1;
    if (pid == 0) {
        res = execve(path, argv, env);
        if (res == -1 && errno == ENOEXEC)
            return archi_error(path);
        if (res == -1 && errno == EACCES)
            return access_exec(path);
    }
    waitpid(pid, &sh->status, 0);
    sig_handler(sh->status);
    return WEXITSTATUS(sh->status);
}
