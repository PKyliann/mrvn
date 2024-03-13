/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** my_repeat.c
*/

#include "../../include/minishell.h"

bool is_num(const char* chaine)
{
    for (int i = 0; chaine[i] != '\0'; i++) {
        if (chaine[i] < '0' || chaine[i] > '9')
            return false;
    }
    return true;
}

int my_repeat(global_t *sh)
{
    if (len_array(sh->shell_array) == 1) {
        printf("repeat: Too few arguments.\n");
        return 84;
    }
    if (is_num(sh->shell_array[1]) != true) {
        printf("repeat: Badly formed number.\n");
        return 84;
    }
    if (sh->shell_array[2] == NULL) {
        printf("repeat: Too few arguments.\n");
        return 84;
    }
    int num_loop = my_getnbr(sh->shell_array[1]);
    char *dest = my_concat_strings(&sh->shell_array[2]);
    char **src = my_str_to_words_array(dest);
    sh->shell_array = src;
    for (int i = 0; i < num_loop; ++i)
        hub(sh);
    return 0;
}
