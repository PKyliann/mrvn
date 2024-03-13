/*
** EPITECH PROJECT, 2023
** parentheses
** File description:
** test_parentheses
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

Test(detect_parenthesis, valid) {
    char *shell_command[] = {"echo", "hello", "(", "world", ")", NULL};
    int result = detect_parenthesis(shell_command);
    cr_assert_eq(result, 0);
}

Test(detect_parenthesis, too_many_opening_parenthesis) {
    char *shell_command[] = {"echo", "(", "(", "world", ")", NULL};
    int result = detect_parenthesis(shell_command);
    cr_assert_eq(result, -1);
}

Test(detect_parenthesis, too_many_parenthesis) {
    char *shell_command[] = {"echo", "hello", ")", ")", NULL};
    int result = detect_parenthesis(shell_command);
    cr_assert_eq(result, -1);
}
