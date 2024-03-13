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
    char **shell_command;
    struct termios old_tio, new_tio;
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
    sh->old_tio = &old_tio; sh->new_tio = &new_tio;
    while (1) {
        signal(SIGINT, handle_signal);
        if (isatty(0))
            my_printf("$>");
        shell_line = malloc(sizeof(char) * 1024);
        int index = handle_input(shell_line, sh);
        printf("\n");
        if (index == 0)
            continue;
        shell_command = str_to_array_delim(shell_line, ";");
        parse_command_line(sh, shell_command);
        free(shell_line);
    }
}
