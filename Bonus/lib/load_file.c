/*
** EPITECH PROJECT, 2023
** B-MUL-200-NCE-2-1-myrpg-mathis.gheri
** File description:
** load_file.c
*/

#include "../include/minishell.h"

char **load_file(char *script_path)
{
    struct stat stats; stat(script_path, &stats);
    int fd = open(script_path, O_RDONLY);
    if (fd == -1)
        return NULL;
    char *buff = malloc(sizeof(char) * (stats.st_size + 1));
    int rd = read(fd, buff, stats.st_size);
    if (rd == -1)
        return NULL;
    buff[rd] = '\0';
    char **words = my_str_to_words_array(buff);
    free(buff); close(fd);
    return words;
}

char **load_file_line(char *script_path)
{
    struct stat stats; stat(script_path, &stats);
    int fd = open(script_path, O_RDONLY);
    if (fd == -1)
        return NULL;
    char *buff = malloc(sizeof(char) * (stats.st_size + 1));
    int rd = read(fd, buff, stats.st_size);
    if (rd == -1)
        return NULL;
    buff[rd] = '\0';
    char **words = my_str_to_str_array(buff);
    free(buff); close(fd);
    return words;
}
