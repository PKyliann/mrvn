/*
** EPITECH PROJECT, 2022
** my_putnbr_base.c
** File description:
** task 18 day 6
*/

#include <stdio.h>
void my_putchar(char c);
int my_strlen(char const *str);

int my_putnbr_base(long nbr, char const *base)
{
    int l = 0;
    int r = 0;
    if (nbr == -2147483648)
        return nbr;
    if (nbr < 0) {
        nbr = nbr * - 1;
        my_putchar(45);
    }
    l = my_strlen(base);
    r = nbr % l;
    nbr = nbr / l;
    if (nbr != 0) {
        my_putnbr_base(nbr, base);
    }
    my_putchar(base[r]);
    return nbr;
}
