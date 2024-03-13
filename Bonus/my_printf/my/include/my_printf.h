/*
** EPITECH PROJECT, 2022
** mini printf
** File description:
** f
*/

#include <stdarg.h>

#ifndef MY_PRINTF
    #define MY_PRINTF

    int my_printf(char const *format, ...);
    int my_put_uns(unsigned int nb);
    void d_int(va_list list);
    void d_str(va_list list);
    void d_char(va_list list);
    void d_prc(va_list list);
    void d_uns(va_list list);
    void d_oct(va_list list);
    void d_hex(va_list list);
    void d_upphex(va_list list);
    void d_bin(va_list list);
    void d_sf(va_list list);
    void d_add(va_list list);
    void d_float(va_list list);
    int my_put_float(double nb);
    void d_floatsc(va_list list);
    int my_put_floatsc(double nb);
    void d_floatscupp(va_list list);
    int my_put_floatscupp(double nb);

#endif
