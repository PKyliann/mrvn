/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** history_ll.c
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

int my_history(global_t *sh)
{
    history_t *tmp = *sh->history;
    for (; tmp; tmp = tmp->next)
        printf("%6d\t%s\t%s\n", tmp->index, tmp->time, (char *) tmp->data);
    return 0;
}

void create_load_history(global_t *sh, history_t **history)
{
    char *filepath = NULL;
    llenv_s *head = (*sh->env_ll);
    for (; head; head = head->next) {
        if (strncmp(head->data, "SAVEPOTAT=", 10) == 0) {
            filepath = &head->data[10];
            break;
        }
    }
    char **file = load_file_line(filepath);
    if (!file)
        return;
    for (int i = 0; file[i] != NULL; i++) {
        char **result = str_to_array_delim(file[i], ";");
        int res = my_getnbr(result[0]);
        add_list_history(history, result[2], &res, result[1]);
    }
    sh->history = history;
}

void write_in_history_file(history_t *tmp, FILE *file)
{
    for (; tmp != NULL; tmp = tmp->next)
        fprintf(file, "%d;%s;%s\n", tmp->index, tmp->time, (char *) tmp->data);
}

void add_to_history_file(global_t *sh, llenv_s **env_ll)
{
    char *filepath = NULL; history_t *tmp = *sh->history;
    llenv_s *head = (*env_ll);
    for (; head; head = head->next) {
        if (strncmp(head->data, "SAVEPOTAT=", 10) == 0) {
            filepath = &head->data[10];
            break;
        }
    }
    if (filepath) {
        FILE *file = fopen(filepath, "w+");
        if (file) {
            write_in_history_file(tmp, file);
            fclose(file);
        } else
            return;
    } else
        return;
}
