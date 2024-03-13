/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** puzzle.c
*/

#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

int contain_op(char *str)
{
    for (int x = 0; str[x] != '\0' ; x++) {
        if (str[x] == '<' || str[x] == '>' || str[x] == '&' || str[x] == '|')
            return 1;
    }
    return 0;
}

char **do_puzz(int *x, char **shell_array)
{
    for (; shell_array[*x - 1]; x++) {
        if (contain_op(shell_array[*x]) != 0 && *x != 0) {
            break;
        }
        shell_array[*x] = shell_array[*x + 1];
    }
    return shell_array;
}

char **puzzle(char **shell_array)
{
    int len = my_strlen(shell_array[0]);
    char *temp; int x = 0;
    if (len > 2) {
        temp = shell_array[0];
        shell_array = do_puzz(&x, shell_array);
        shell_array[x - 1] = temp;
    } else {
        temp = shell_array[1];
        shell_array[1] = shell_array[0];
        shell_array[0] = temp;
    }
    return shell_array;
}

int do_puzz_redit(int o, int i, int ref)
{
    if (i >= ref) {
        o++; o++;
    }
    return o;
}

char **puzzle_redir(char **shell_array)
{
    int i;
    for (i = 0; shell_array[i]; i++) {
        if (strncmp(shell_array[i], ">", 1) == 0)
            break;
    } int j; int cpt; int ref = i;
    for (j = i, cpt = 0; shell_array[j] != NULL; j++, cpt++);
    if (cpt > 2) {
        char *temp = shell_array[ref];
        char *temp_bis = shell_array[ref + 1];
        int o = 0;
        int len_a = len_array(shell_array);
        for (i = 0; i < len_a - 2; i++, o++) {
            o = do_puzz_redit(o, i, ref);
            shell_array[i] = shell_array[o];
        }
        shell_array[i] = temp; shell_array[i + 1] = temp_bis;
    }
    return shell_array;
}
