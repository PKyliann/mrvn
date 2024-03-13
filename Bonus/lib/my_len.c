/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** mini-shell
*/

int my_len(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}
