/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** test_strtostr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"


Test(my_str_to_str_array, empty_input) {
    char *input = "";
    char **result = my_str_to_str_array(input);
    cr_assert_not_null(result);
    cr_assert_null(result[0]);
}

Test(my_str_to_str_array, multi_line_input) {
    char *input = "potat\ngang\ncorp\nare\n";
    char **result = my_str_to_str_array(input);
    cr_assert_not_null(result);
    cr_assert_str_eq(result[0], "potat");
    cr_assert_str_eq(result[1], "gang");
    cr_assert_str_eq(result[2], "corp");
    cr_assert_str_eq(result[3], "are");
    cr_assert_null(result[4]);
}
