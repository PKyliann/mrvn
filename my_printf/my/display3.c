/*
** EPITECH PROJECT, 2022
** display for printf
** File description:
** 3rd display
*/

int my_putnbr_base(long nbr, char const *base);
void my_putchar(char c);
int my_put_floatsc(double nb);
int my_put_floatscupp(double nb);
#include <stdarg.h>
#include "include/my_printf.h"

void d_add(va_list list)
{
    my_putchar('0');
    my_putchar('x');
    unsigned long to_display = (unsigned long)va_arg(list, unsigned long);
    my_putnbr_base(to_display, "0123456789abcdef");
}

void d_float(va_list list)
{
    double nb = va_arg(list, double);
    my_put_float(nb);
}

void d_floatsc(va_list list)
{
    double nb = va_arg(list, double);
    my_put_floatsc(nb);
}

void d_floatscupp(va_list list)
{
    double nb = va_arg(list, double);
    my_put_floatscupp(nb);
}
