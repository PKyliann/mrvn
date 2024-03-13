/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** init_history.c
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

void init_list_history(history_t **head, void *data, char *time_str)
{
    history_t *new = malloc(sizeof(history_t));
    new->data = data;
    new->time = strdup(time_str);
    new->index = 1;
    new->prev = NULL;
    new->next = NULL;
    *head = new;
}

void add_list_history(history_t **head, void *data, int *index, char *time_str)
{
    char **t = my_str_to_words_array(data);
    data = my_concat_strings(t);
    if (*head == NULL) {
        init_list_history(head, data, time_str);
        return;
    }
    history_t *node = malloc(sizeof(history_t));
    node->index = *index;
    node->data = data;
    node->time = strdup(time_str);
    node->next = NULL;
    history_t *last = *head;
    while (last->next != NULL)
        last = last->next;
    node->prev = last;
    last->next = node;
}

void create_history_var(llenv_s *env_ll)
{
    char *filepath = getcwd(NULL, 0);
    filepath = my_strcat(filepath, "/save/history");
    char *save = my_strcat("setenv ", "SAVEPOTAT ");
    save = my_strcat(save, filepath);
    char **savepath = my_str_to_words_array(save);
    my_setenv(savepath, &env_ll);
}

int len_list(history_t **history)
{
    int cmp = 0;
    history_t *tmp = *history;
    for (; tmp; tmp = tmp->next, cmp++);
    return cmp;
}
