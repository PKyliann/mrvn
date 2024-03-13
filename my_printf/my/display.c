/*
** EPITECH PROJECT, 2022
** display
** File description:
** for my print f
*/

#include <stdarg.h>
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_put_uns(unsigned int nb);

void d_int(va_list list)
{
    int to_display = va_arg(list, int);
    my_put_nbr(to_display);
}

void d_str(va_list list)
{
    char *to_display = va_arg(list, char*);
    my_putstr(to_display);
}

void d_char(va_list list)
{
    char to_display = va_arg(list, int);
    my_putchar(to_display);
}

void d_prc(va_list list)
{
    my_putchar('%');
}

void d_uns(va_list list)
{
    unsigned int to_display = va_arg(list, unsigned int);
    my_put_uns(to_display);
}
