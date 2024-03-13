/*
** EPITECH PROJECT, 2022
** my_put_floatsc.c
** File description:
** display number in scientist
*/
#include <stdio.h>
int my_put_nbr(int nb);
int my_putchar(char c);

static int my_power(int nb)
{
    int i;
    int count = 0;
    for (i = 0; nb >= 10; i++) {
        count++;
        nb = nb / 10;
    }
    return count;
}

static int my_compute_power_rec(int nb, int p)
{
    int n;
    n = nb;
    if (p == 1) {
        return n;
    }
    if (p == 0) {
        return 1;
    } else if (p < 0) {
        return 0;
    }
    return (my_compute_power_rec(n, p - 1) * nb);
}

int my_put_floatsc(double nb)
{
    int p_ent = (int) nb;
    int p = my_power(p_ent);
    int pow = my_compute_power_rec(10, p);
    nb = nb / pow;
    p_ent = (int) nb;
    int pdec = (nb - p_ent) * 1000000;
    my_put_nbr(p_ent);
    my_putchar('.');
    my_put_nbr(pdec);
    my_putchar('e');
    if (p < 0)
        my_putchar('-');
    else
        my_putchar('+');
    if (p < 10 && p >= 0)
        my_putchar('0');
    my_put_nbr(p);
    return 1;
}
