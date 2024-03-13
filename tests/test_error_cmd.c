/*
** EPITECH PROJECT, 2023
** test
** File description:
** test_error_cmd
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

Test(access_exec, permission_denied, .init = cr_redirect_stderr) {
    char *path = "/usr/bin/some_file";
    int result = access_exec(path);
    cr_assert_eq(result, -1);
    char *expected_message = "/usr/bin/some_file: Permission denied.\n";
    cr_assert_stderr_eq_str(expected_message);
}

Test(archi_error, wrong_architecture, .init = cr_redirect_stderr) {
    char *path = "/path/to/executable";
    int error_code = archi_error(path);
    cr_assert_eq(error_code, -1, "Expected error code -1");

    char *expected_message =
            "/path/to/executable: Exec format error. Wrong Architecture.\n";
    cr_assert_stderr_eq_str(expected_message, "Expected error message");
}

Test(err_var, invalid_name, .init = cr_redirect_stderr) {
    char *name = "1foo";
    char *value = "bar";
    int res = err_var(name);
    int exp = 1;
    cr_assert_eq(res, 1);
    char *expected = "set: Variable name must start with a letter.\n";
    cr_assert_stderr_eq_str(expected);
}

Test(err_var, inv_name, .init = cr_redirect_stderr) {
    char *name = "l_o";
    char *value = "bar";
    int res = err_var(name);
    int exp = 1;
    cr_assert_eq(res, 1);
    char *expected =
            "set: Variable name must contain alphanumeric characters.\n";
    cr_assert_stderr_eq_str(expected);
}
