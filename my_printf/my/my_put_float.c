/*
** EPITECH PROJECT, 2022
** my_put_float.c
** File description:
** display floats
*/

#include <stdarg.h>
#include <stdio.h>


int my_put_nbr(int nb);
int my_putchar(char c);

//rajouter sécurité pour dépassement valeur

int my_put_float(double nb)
{
    int p_ent = (int) nb;
    int pdec = (nb - p_ent) * 1000000;
    my_put_nbr(p_ent);
    my_putchar('.');
    my_put_nbr(pdec);
    return 1;
}
