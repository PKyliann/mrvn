/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** my_concat_array.c
*/

#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

char **my_array_concat(char *alias, char **array_add)
{
    char **array_ref = my_str_to_words_array(alias);
    if (!array_ref || ! array_add)
        return NULL;
    int i = 0; int a = 0; int j = 0;
    int len_a1 = len_array(array_ref);
    int len_a2 = len_array(array_add);
    char **dest = malloc(sizeof(char *) * (len_a1 + len_a2));
    for (j = 0; array_ref[j]; j++, a++) {
        dest[a] = strdup(array_ref[j]);
    }
    for (i = 1; i < len_a1; i++, a++) {
        dest[a] = strdup(array_add[i]);
    }
    dest[a] = NULL;
    return dest;
}
