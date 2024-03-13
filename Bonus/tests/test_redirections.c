/*
** EPITECH PROJECT, 2023
** test
** File description:
** redirect
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

Test(comp_redir, double_greater_than) {
    char *shell_line = "ls >> output.txt";
    int expected = 2;
    int result = comp_redir(shell_line);
    cr_assert_eq(expected, result);
}

Test(comp_redir, double_less_than) {
    char *shell_line = "sort << input.txt";
    int expected = 0;
    int result = comp_redir(shell_line);
    cr_assert_eq(expected, result);
}

Test(comp_redir, invalid_redir) {
    char *shell_line = "cat file.txt | grep keyword";
    int expected = -1;
    int result = comp_redir(shell_line);
    cr_assert_eq(expected, result);
}
