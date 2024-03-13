/*
** EPITECH PROJECT, 2023
** operators
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

Test(and_error, invalid_input) {
    global_t sh;
    char *shell_array[] = {"&&", NULL};
    sh.shell_array = shell_array;
    int result = and_error(&sh);
    cr_assert_eq(result, 84);
}

Test(and_error, command_is_null) {
    global_t sh;
    char *shell_array[] = {NULL};
    sh.shell_array = shell_array;
    int ex = and_error(&sh);
    cr_assert_neq(ex, 84);
}

Test(or_error, is_empty) {
    char *result[] = {"", NULL};
    int expected = or_error(result);
    cr_assert_eq(expected, 84);
}
