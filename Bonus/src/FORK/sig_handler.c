/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"


void sig_handler(int status)
{
    if (WIFSIGNALED(status) != 0) {
        char *sig = strsignal(WTERMSIG(status));
        int len = my_strlen(sig);
        if (my_strcmp(sig, "Floating point exception") == 0)
            write(2, "Floating exception", 18);
        else
            write(2, sig, len);
        write(2, "\n", 1);
    }
}
