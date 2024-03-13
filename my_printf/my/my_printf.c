/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** printing
*/

void my_putchar(char c);
#include <stdarg.h>
#include "./include/my_printf.h"
#include "./include/my.h"

int flag_finder(char c)
{
    char *flag_f = "disc%uoxXbSpfFeE";
    for (int i = 0; flag_f[i] != '\0'; i++) {
        if (flag_f[i] == c)
            return i;
    }
    return (-1);
}

int my_printf2(char const *format, va_list argp, int i)
{
    void (*fc_ptr[16])(va_list) = { &d_int, &d_int, &d_str, &d_char, \
        &d_prc, &d_uns, &d_oct, &d_hex, &d_upphex, &d_bin, &d_sf, \
        &d_add, &d_float, &d_float, &d_floatsc, &d_floatscupp };
    int flag;
    char c;
    if (format[i] == '%') {
        i++;
        c = format[i];
        flag = flag_finder(c);
        if (flag == -1)
            return 84;
        (*fc_ptr[flag])(argp);
    } else {
        my_putchar(format[i]);
    }
    return i;
}

int my_printf(char const *format, ...)
{
    int i;
    va_list argp;
    va_start(argp, format);
    for (i = 0; format[i] != '\0'; i++) {
        int ret = my_printf2(format, argp, i);
        if (ret == 84)
            return 84;
        i = ret;
    }
    va_end(argp);
    return 0;
}
