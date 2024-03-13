/*
** EPITECH PROJECT, 2022
** my_put_floathex.c
** File description:
** display float in hex format
*/

#include <stdio.h>

void my_putchar(char c);
int my_putnbr_base(int nb, char *base);

int my_put_floathex(double nb, char *base)
{
    int p_ent = (int) nb;
    int p_dec = (nb - p_ent) * 1000000;
    my_putchar('0');
    my_putchar('x');
    my_putnbr_base(p_ent, base);
    my_putchar('.');
    my_putnbr_base(p_dec, base);
    return 1;
}
