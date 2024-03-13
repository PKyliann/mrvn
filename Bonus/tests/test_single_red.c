/*
** EPITECH PROJECT, 2023
** test
** File description:
** test_single_red
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

Test(comp_redir, less_than) {
    char *shell_line = "cat < file.txt";
    int expected = 1;
    int result = comp_redir(shell_line);
    cr_assert_eq(expected, result);
}

Test(comp_redir, greater_than) {
    char *shell_line = "grep keyword > results.txt";
    int expected = 3;
    cr_assert_eq(expected, comp_redir(shell_line));
}
