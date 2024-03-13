/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** test_strdup
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

Test(my_strdup, dup_basic_test) {
    char *src = "Hello, world!";
    char *expected = src;
    char *result = my_strdup(src);
    cr_assert_str_eq(expected, result);
}

Test(my_strdup, empty_string_test) {
    char *src = "";
    char *expected = src;
    char *result = my_strdup(src);
    cr_assert_str_eq(expected, result);
}
