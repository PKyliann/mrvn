/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** test_path_wslash
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

Test(start_w_slash, no_slash) {
    char *line = "hello world";
    int expected = 0;
    int result = start_w_slash(line);
    cr_assert_eq(expected, result);
}

Test(start_w_slash, with_slash) {
    char *line = "/bin/ls";
    int expected = 1;
    int result = start_w_slash(line);
    cr_assert_eq(expected, result);
}

Test(start_w_slash, empty_line) {
    char *line = "";
    int expected = 0;
    int result = start_w_slash(line);
    cr_assert_eq(expected, result);
}

Test(start_w_slash, null_line) {
    char *line = NULL;
    int expected = 0;
    int result = start_w_slash(line);
    cr_assert_eq(expected, result);
}
