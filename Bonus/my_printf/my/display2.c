/*
** EPITECH PROJECT, 2022
** display2
** File description:
** for my printf
*/

#include <stdarg.h>
int my_putnbr_base(int nbr, char *base);
int my_strprint(char *str);

void d_oct(va_list list)
{
    int to_display = va_arg(list, int);
    my_putnbr_base(to_display, "01234567");
}

void d_hex(va_list list)
{
    int to_display = va_arg(list, int);
    my_putnbr_base(to_display, "0123456789abcdef");
}

void d_upphex(va_list list)
{
    int to_display = va_arg(list, int);
    my_putnbr_base(to_display, "0123456789ABCDEF");
}

void d_bin(va_list list)
{
    unsigned int to_display = va_arg(list, unsigned int);
    my_putnbr_base(to_display, "01");
}

void d_sf(va_list list)
{
    char *to_display = va_arg(list, char *);
    my_strprint(to_display);
}
