/*
** EPITECH PROJECT, 2023
** setenv_tests
** File description:
** 42sh
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

Test(my_setenv, not_n_alphanum, .init = cr_redirect_stderr) {
    char *tab[] = {
        "LS_COLOR42"
    };
    char *env[] = {
        "BINJOUR=21"
    };
    llenv_s *env_ll = NULL;
    create_ll(&env_ll, env);
    error_handling(0);
    char *expected =
            "setenv: Variable name must contain alphanumeric characters.\n";
    cr_assert_stderr_eq_str(expected);
}

Test(setnv, invalid_cmd) {
    char *invalid_input[] = {"command", "arg1", NULL};
    int expected = 84;
    cr_assert_eq(check_param(invalid_input), expected);
}
