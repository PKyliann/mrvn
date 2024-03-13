/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** my_concat_strings.c
*/

#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

char *my_concat_strings(char **shell_array)
{
    char **array = dup_array(shell_array);
    if (array == NULL)
        return NULL;
    int initial_size = 256;
    char *buff = malloc(initial_size * sizeof(char));
    if (buff == NULL)
        return NULL;
    buff[0] = '\0';
    int len_buff = 0;
    int len_arr = 0;
    for (int i = 0; array[i] != NULL; i++) {
        len_buff = strlen(buff);
        array[i] = my_strcat(array[i], " ");
        len_arr = strlen(array[i]);
        buff = realloc(buff, len_buff + len_arr + 1);
        buff = my_strcat(buff, array[i]);
    }
    return buff;
}

char *concat_strings(char **strings)
{
    int length = 0;
    int i;
    for (i = 0; strings[i] != NULL; i++)
        length += strlen(strings[i]);
    char *result = malloc(length + 1);
    if (result == NULL)
        return NULL;
    int offset = 0;
    for (i = 0; strings[i] != NULL; i++) {
        memcpy(result + offset, strings[i], strlen(strings[i]));
        offset += strlen(strings[i]);
    }
    result[length] = '\0';
    return result;
}
