/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** hub_termios.c
*/

#include "../../include/minishell.h"

void handle_arrow_keys(history_t **hist, char **line, int *index, int *init)
{
    getchar();
    switch (getchar()) {
        case 'A':
            up_arrow(hist, line, index, init);
            break;
        case 'B':
            down_arrow(hist, line, index, init);
            break;
    }
}

int handle_input(char *shell_line, global_t *sh)
{
    int c, index = 0; history_t *hist = *sh->history;
    if (hist != NULL && hist->data != NULL)
        for (; hist->next; hist = hist->next);
    history_t *current_hist = hist;
    int init = 1;
    while ((c = getchar()) != '\n') {
        switch (c) {
            case '\033':
                handle_arrow_keys(&current_hist, &shell_line, &index, &init);
                break;
            case 127:
                backspace(shell_line, &index);
                break;
            default:
                character_input(c, shell_line, &index);
                break;
        }
    }
    history_add(shell_line, sh);
    return index;
}
