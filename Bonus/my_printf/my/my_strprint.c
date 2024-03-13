/*
** EPITECH PROJECT, 2022
** my_strprint.c
** File description:
** display string with unprintable character
*/

#include "include/my.h"
int my_str_isprintable(char const *str);
int my_putnbr_base(int nbr, char const *base);
void my_putchar(char c);

static int comparison(char c)
{
    if ( c >= 32 && c <= 126)
        return 1;
    return 0;
}

int my_strprint(char *str)
{
    int a = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (comparison(str[i]) == 0) {
            my_putchar('\\');
            a = str[i];
            my_putnbr_base(a, "01234567");
        } else {
            my_putchar(str[i]);
        }
    }
    return 1;
}
