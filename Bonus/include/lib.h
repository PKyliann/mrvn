/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** lib.h
*/

#ifndef B_PSU_200_NCE_2_1_42SH_MATHIS_GHERI_LIB_H
    #define B_PSU_200_NCE_2_1_42SH_MATHIS_GHERI_LIB_H
    #include "minishell.h"

//lib/create_triple_array.c
char ***assemble_commands(char **shell_array, int x);
char ***assemble_lines(char **shell_array);
char ***assemble_command(char **shell_array);
void *my_realloc(void *ptr, int len);

//lib/str_to_array_delim.c
char **str_to_array_delim(char *str, char *lim);

//lib/my_getnbr.c
int my_getnbr(char *str);

//lib/my_str_to_str_array.c
char **my_str_to_str_array(char *str);

//lib/my_str_to_str_darray.c
char **my_str_to_str_drarray(char *str);

//lib/my_str_to_str_parray.c
char **my_str_to_str_parray(char *str);

//lib/my_str_to_str_rarray.c
char **my_str_to_str_rarray(char *str);

//lib/my_str_to_words_array.c
char **my_str_to_words_array(char *str);
char *my_strncpy(char *dest, char const *src, int n);

//lib/my_strcat.c
char *my_strcat(char *dest, char *src);

//lib/my_concat.c
char *make_path(char *line, char *path_var);
//char *my_concat(char *path, char *str);
char *my_concat(const char *path, const char *str);
//char *concat_path(char *shell_line);
char *concat_path(char *slash, char *shell_line);

//lib/my_len.c
int my_len(char *str);

//lib/my_path_array.c
char **my_path_array(char *str);

//lib/my_path_to_array.c
char **my_path_to_array(char *str);

//lib/my_strcpm.c
int my_strcmp_shell(char *s1, char *s2);
int my_strcmp(char *s1, char *s2);

//lib/my_strcpy.c
char *my_strcpy(char *dest, char const *src);

//lib/my_strdup.c
char *my_strdup(char const *src);

//lib/my_strncpm.c
int my_strncmp(char const *s1, char const *s2, int n);

//lib/path_gestion.c
char *concat_array(char **shell_array);
int contain_equaliser(char **shell_array);
int char_isalpha(char c);
int is_alpha_num(char c);
int ret_value(char *shell);

//lib/start_w_slash.c
int start_w_slash(char const *shell_line);

//lib/len_array.c
int len_array(char **array);
int len_triple(char ***triple);

//lib/my_concat_strings.c
char *concat_strings(char **strings);
char *my_concat_strings(char **array);

//lib/my_free.c
void my_free_array(char **array);
void my_free(char ***commands);

//lib/puzzle.c
char **puzzle(char **shell_array);
int contain_op(char *str);
char **puzzle_redir(char **shell_array);

//lib/my_concat_array.c
char **my_array_concat(char *alias, char **array_add);

//lib/dup_array.c
char **dup_array(char **array);

//lib/display_array.c
void display_array(char **array);

#endif //B_PSU_200_NCE_2_1_42SH_MATHIS_GHERI_LIB_H
