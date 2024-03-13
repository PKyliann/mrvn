/*
** EPITECH PROJECT, 2023
** unit_tests
** File description:
** 42sh
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

Test(handle_input, valid_input, .init = cr_redirect_stdout) {
    char input[] = "ls -l";
    char *expected = "ls -l\n";
    my_printf(input);
    cr_assert_stdout_eq_str(input);
}

Test(handle_input, valid, .init = cr_redirect_stdout) {
    char input[] = "wxdfcvb89";
    char *expected = "wxdfcvb89: Command not found.\n";
    command_error(input);
    cr_assert_stdout_eq_str(expected);
}

Test(handle_input, vld) {
    char *input = "sdxfc<qgvsjkfhlh";
    int expected = - 1;
    cr_assert_eq(command_error(input), expected);
}
