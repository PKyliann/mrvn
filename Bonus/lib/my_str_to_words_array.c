/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

#include "../include/minishell.h"

int is_alphanum(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
        return 0;
    return 1;
}

static int count_words(char *str)
{
    int count = 0;
    int i = 0;
    for (; str[i] != '\0'; i++) {
        if ((is_alphanum(str[i]) == 1) && is_alphanum(str[i + 1]) == 0)
            count++;
    }
    return count;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    if (n > my_strlen(src)) {
        dest[i] = '\0';
    }
    return dest;
}

char **my_str_to_words_array(char *str)
{
    int nbr_words = count_words(str);
    char **array = malloc(sizeof(char *) * (nbr_words + 1));
    int a; int i = 0; int size = 0;
    if (array == NULL)
        return NULL;
    for (a = 0; str[a] != '\0'; a++) {
        if (is_alphanum(str[a]) != 0)
            size++;
        if (is_alphanum(str[a]) != 0 && is_alphanum(str[a + 1]) == 0) {
            array[i] = malloc(sizeof(char) * (size + 1));
            memset(array[i], 0, sizeof(char) * (size + 1));
            my_strncpy(array[i], &str[a - size + 1], size);
            size = 0;
            i++;
        }
    }
    array[i] = NULL;
    return array;
}
