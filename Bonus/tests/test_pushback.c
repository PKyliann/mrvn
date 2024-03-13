/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** test_pushback
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"
#include "../my_printf/my/include/my_printf.h"


Test(push_back, empty_list) {
    llenv_s *env = NULL;
    push_back(&env, "first data");
    cr_assert_not_null(env);
    cr_assert_str_eq(env->data, "first data");
    cr_assert_null(env->next);
}

Test(push_back, non_empty_list) {
llenv_s *env = NULL;
push_back(&env, "first data");
push_back(&env, "second data");
push_back(&env, "third data");
cr_assert_not_null(env);
cr_assert_str_eq(env->data, "first data");
cr_assert_not_null(env->next);
cr_assert_str_eq(env->next->data, "second data");
cr_assert_not_null(env->next->next);
cr_assert_str_eq(env->next->next->data, "third data");
cr_assert_null(env->next->next->next);
}
