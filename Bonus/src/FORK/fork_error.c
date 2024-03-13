/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"
#include "../../my_printf/my/include/my.h"

int access_exec(char *path)
{
    write(2, path, my_strlen(path));
    write(2, ": Permission denied.\n", 21);
    return -1;
}

int archi_error(char *path)
{
    write(2, path, my_strlen(path));
    write(2, ": Exec format error. Wrong Architecture.\n", 41);
    return -1;
}

int command_error(char *path)
{
    my_printf("%s: Command not found.\n", path);
    return -1;
}
