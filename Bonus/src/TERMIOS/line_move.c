/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** line_move.c
*/

#include "../../include/minishell.h"

void up_arrow(history_t **hist, char **line, int *index, int *init)
{
    if (*init) {
        *init = 0;
    } else if ((*hist)->prev != NULL && (*hist)->prev->data != NULL) {
        *hist = (*hist)->prev;
    }
    if (*hist != NULL && (*hist)->data != NULL) {
        printf("\r\033[K");
        *line = strcpy(*line, (*hist)->data);
        printf("$>%s", *line);
        *index = strlen(*line);
    }
}

void down_arrow(history_t **hist, char **line, int *index, int *init)
{
    if ((*hist)->next != NULL && (*hist)->next->data != NULL) {
        *hist = (*hist)->next;
        printf("\r\033[K");
        *line = strcpy(*line, (*hist)->data);
        printf("$>%s", *line);
        *index = strlen(*line);
    } else {
        printf("\r\033[K");
        *line = strcpy(*line, "");
        printf("$>%s", *line);
        *init = 1;
    }
}

void backspace(char *shell_line, int *index)
{
    if (*index > 0) {
        (*index)--;
        shell_line[*index] = '\0';
        printf("\b \b");
    }
}

void character_input(char c, char *shell_line, int *index)
{
    putchar(c);
    shell_line[*index] = c;
    (*index)++;
    shell_line[*index] = '\0';
}
