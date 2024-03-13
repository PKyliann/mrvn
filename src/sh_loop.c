/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

global_t *getstruct(void)
{
    static global_t sh;
    return &sh;
}

void history_add(char *shell_line, global_t *sh)
{
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char time_str[20];
    strftime(time_str, 20, "%H:%M", tm_info);
    char *new_command = strdup(shell_line);
    int len = 0;
    if (*sh->history != NULL)
        len = len_list(sh->history) + 1;
    history_t *tmp = *sh->history;
    if (*sh->history == NULL) {
        add_list_history(sh->history, new_command, &len, time_str);
        return;
    }
    for (; tmp->next; tmp = tmp->next);
    if (strncmp(shell_line, tmp->data, strlen(tmp->data) - 1) == 0) {
        tmp->time = strdup(time_str);
        return;
    }
    add_list_history(sh->history, new_command, &len, time_str);
    free(new_command);
}

void parse_command_line(global_t *sh, char **shell_command)
{
    for (int i = 0; shell_command[i] != NULL; i++) {
        sh->shell_array = my_str_to_words_array(shell_command[i]);
        parse_command(sh);
    }
}

void sh_loop(char *shell_line, global_t *sh)
{
    int get; char **shell_command; size_t size = 0;
    while (1) {
        signal(SIGINT, handle_signal);
        if (isatty(0))
            my_printf("$>");
        get = getline(&shell_line, &size, stdin);
        history_add(shell_line, sh);
        if (get == -1)
            break;
        if (my_strcmp_shell("\n", shell_line) == 0)
            continue;
        shell_command = str_to_array_delim(shell_line, ";");
        if (my_strlen(shell_command[0]) == 0)
            continue;
        parse_command_line(sh, shell_command);
    }
}
