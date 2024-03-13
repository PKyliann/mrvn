/*
** EPITECH PROJECT, 2023
** test
** File description:
** test_pipe
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"

Test(pipe_compare, different_strings) {
    char *str1 = "potate";
    char *str2 = "truite";
    int expected = 1;
    cr_assert_eq(my_comp(str1, str2), expected);

}

Test(pipe_compare, same_strings) {
    char *str1 = "ls -l";
    char *str2 = "ls -l";
    int expected = 0;
    cr_assert_eq(my_comp(str1, str2), expected);

}
