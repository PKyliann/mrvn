/*
** EPITECH PROJECT, 2023
** my_echo
** File description:
** 42sh
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

void e_flag_case(char *arg)
{
    for (int j = 0; arg[j] != '\0'; j++){
        switch (arg[j]) {
        case '\\': j++;
            switch (arg[j]) {
            case 'n':
                my_putchar('\n'); break;
            case 't':
                my_putchar('\t');
                break;
            case 'r':
                my_putchar('\r'); break;
            default:
                my_putchar(arg[j]);
                break;
            }
            break;
        default: my_putchar(arg[j]);
            break;
        }
    }
}

void flags(char *arg, int *e_flag, int *n_flag)
{
    if (my_strcmp(arg, "-e") == 0){
        *e_flag = 1;
    }
    if (my_strcmp(arg, "-E") == 0){
        *e_flag = 0;
    }
    if (my_strcmp(arg, "-n") == 0){
        *n_flag = 1;
    }
}

int my_echo(char **shell_array, llenv_s **env_ll)
{
    if (!env_ll)
        return 1;
    int e_flag = 1;
    int n_flag = 0; int argc = 0;
    for (int i = 0; shell_array[i] != NULL; i++)
        argc++;
    for (int i = 1; i < argc; i++)
        flags(shell_array[i], &e_flag, &n_flag);
    for (int i = 1; i < argc; i++){
        if (my_strcmp(shell_array[i], "-e") == 0 ||
        my_strcmp(shell_array[i], "-E") == 0 ||
        my_strcmp(shell_array[i], "-n") == 0)
            continue;
        e_flag_case(shell_array[i]);
        if (i != argc - 1) my_printf(" ");
    }
    if (!n_flag)
        my_printf("\n");
    return 0;
}
