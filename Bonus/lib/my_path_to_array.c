/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

#include "../include/minishell.h"

static int is_char(char c)
{
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90))
        return 1;
    if ((c >= 97 && c <= 122) || c == 39 || c == 46)
        return 1;
    if (c == '-' || c == '/')
        return 1;
    return 0;
}

static int count_words(char *str)
{
    int count = 0;
    int i = 0;
    for (; str[i] != '\0'; i++) {
        if ((is_char(str[i]) == 1) && is_char(str[i + 1]) == 0)
            count++;
    }
    return count;
}

char **my_path_to_array(char *str)
{
    int nbr_words = count_words(str);
    char **array = malloc(sizeof(char *) * (nbr_words + 1));
    int a; int i = 0; int size = 0;
    if (array == NULL)
        return NULL;
    for (a = 0; str[a] != '\0'; a++) {
        if (is_char(str[a]) != 0)
            size++;
        if (is_char(str[a]) != 0 && is_char(str[a + 1]) == 0) {
            array[i] = malloc(sizeof(char) * (size + 1));
            my_strncpy(array[i], &str[a - size + 1], size);
            size = 0;
            i++;
        }
    }
    array[i] = NULL;
    return array;
}
