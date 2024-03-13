/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** return smth
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
