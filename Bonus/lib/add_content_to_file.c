/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** add_content_to_file.c
*/

#include "../include/minishell.h"

void add_to_file(char *line, llenv_s **env_ll, char *var)
{
    char *filepath = NULL;
    llenv_s *head = (*env_ll);
    for (; head; head = head->next) {
        if (strncmp(head->data, var, strlen(var)) == 0) {
            filepath = &head->data[strlen(var)];
            break;
        }
    }
    if (filepath) {
        FILE *file = fopen(filepath, "a");
        if (file) {
            fprintf(file, "%s", line);
            fclose(file);
        } else {
            return;
        }
    } else {
        return;
    }
}
