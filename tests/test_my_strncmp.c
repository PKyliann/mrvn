/*
** EPITECH PROJECT, 2022
** test
** File description:
** file
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

int my_strncmp(const char *s1, const char *s2, int n);

Test(my_strncmp, s1_s2_empty) {
    char const s1[] = "";
    char const s2[] = "";
    cr_assert_null(my_strncmp(s1, s2, 1));
}

Test(my_strncmp, same_array) {
    char const s1[] = "hola";
    char const s2[] = "hola";
    cr_assert_eq(my_strncmp(s1, s2, 1), 0);
}

Test(my_strncmp, minus_one) {
    char const s1[] = "";
    char const s2[] = "";
    cr_assert_null(my_strncmp(s1, s2, -1));
}

Test(my_strncmp, five) {
    char const s1[] = "hola";
    char const s2[] = "hola";
    cr_assert_null(my_strncmp(s1, s2, 5));
}

Test(my_strncmp, zero) {
    char const s1[] = "hola";
    char const s2[] = "hola";
    cr_assert_null(my_strncmp(s1, s2, 0));
}
