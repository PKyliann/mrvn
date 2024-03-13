/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** and_op.c
*/

#include "../../include/minishell.h"

int is_operator(char **shell_array)
{
    int cpt = 0;
    for (int i = 0; shell_array[i] != NULL; i++) {
        if (strstr(shell_array[i], "&&") != NULL)
            cpt++;
        if (strstr(shell_array[i], "||") != NULL)
            cpt++;
    }
    return cpt;
}

int nb_operators(char **array)
{
    int cpt = 0;
    for (int i = 0; array[i]; i++) {
        if (strcmp(array[i], "&&") == 0)
            cpt++;
        if (strcmp(array[i], "||") == 0)
            cpt++;
    }
    return cpt;
}

char **fill_op_array(char **array, int nb, char **op)
{
    int b = 0;
    op[b] = " "; b++;
    for (int i = 0; array[i]; i++) {
        if (strcmp(array[i], "&&") == 0) {
            op[b] = "0"; b++;
        }
        if (strcmp(array[i], "||") == 0) {
            op[b] = "1"; b++;
        }
    }
    op[b] = NULL;
    return op;
}

void my_operator(global_t *sh)
{
    if (len_array(sh->shell_array) == 1
    && strstr("&&", sh->shell_array[0]) != NULL)
        return;
    int nb = nb_operators(sh->shell_array);
    char **op = malloc(sizeof(char *) * (nb + 2));
    for (int j = 0; j < nb; j++)
        op[j] = malloc(sizeof(char) * 2);
    op = fill_op_array(sh->shell_array, nb, op);
    sh->res_fork = 0;
    char *buff = my_concat_strings(sh->shell_array);
    char **dest = str_to_array_delim(buff, "&&||");
    for (int a = 0, i = 0; dest[a] != NULL; a++) {
        if ( a == 0 || (sh->status == 0 && strstr(op[i], "0"))
        || (sh->status != 0 && strstr(op[i], "1"))) {
            sh->shell_array = my_str_to_words_array(dest[a]);
            hub(sh);
            i++;
        } else
            i++;
    }
}
