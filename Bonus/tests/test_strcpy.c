/*
** EPITECH PROJECT, 2023
** test
** File description:
** test_strcpy
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"


Test(my_strcpy, copy_in_empty_array) {
    char dest[6] = {0};
    my_strcpy(dest, "Hello");
    cr_assert_str_eq(dest, "Hello");
}

Test(my_strcpy, copy_string_in_empty_array) {
    char dest[6] = {0};
    char *cpy = my_strcpy(dest, "Hello");
    cr_assert_str_eq(cpy, "Hello");
}

Test(my_strcat, concat) {
    char dest[6] = {0};
    char *cat = my_strcat(dest, "Hello");
    cr_assert_str_eq(cat, "Hello");
}

Test(my_concat, concatenates_strings) {
    char *path = malloc(sizeof(char) * 100);
    my_strncpy(path, "hello", 6);
    char *str = " world!";
    char *result = my_concat(path, str);
    char *expected = "hello world!";
    cr_assert_str_eq(expected, result);
}
