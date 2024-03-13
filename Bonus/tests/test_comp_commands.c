/*
** EPITECH PROJECT, 2023
** test
** File description:
** test_comp_commands
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

Test(comp, valid_command) {
    char *cmd = "env";
    int expected = 0;
    int result = comp(cmd);
    cr_assert_eq(expected, result);
}

Test(comp, invalid_command) {
    char *cmd = "potate";
    int expected = -1;
    int result = comp(cmd);
    cr_assert_eq(expected, result);
}

Test(comp, last_command) {
    char *cmd = "cd";
    int expected = 4;
    int result = comp(cmd);
    cr_assert_eq(expected, result);
}
