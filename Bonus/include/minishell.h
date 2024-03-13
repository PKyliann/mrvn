/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** minishell.h
*/

#ifndef B_PSU_200_NCE_2_1_42SH_MATHIS_GHERI_MINISHELL_H
    #define B_PSU_200_NCE_2_1_42SH_MATHIS_GHERI_MINISHELL_H

    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <stddef.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <signal.h>
    #include <string.h>
    #include "../include/lib.h"
    #include "../my_printf/my/include/my_printf.h"
    #include "../my_printf/my/include/my.h"
    #include <termios.h>
    #include <curses.h>
    #include <sys/mman.h>
    #include <stdbool.h>
    #include <time.h>

    #define MAX_ARGS 100
    #define a_c assemble_commands

//Linked list env
typedef struct llenv_t {
    char *data;
    struct llenv_t *next;
} llenv_s;

//Linked list Local Var
typedef struct lvar_s {
    char *name;
    char *value;
    struct lvar_s *next;
} lvar_t;

//Linked list alias
typedef struct alias_s {
    char *name;
    char *data;
    struct alias_s *next;
} alias_t;

//Command struct
typedef struct command_s {
    char *command;
    char op;
} command_t;

//Command struct
typedef struct history_s {
    int index;
    char *data;
    char *time;
    struct history_s *next;
    struct history_s *prev;
} history_t;

//Global struct
typedef struct global_s {
    struct termios *old_tio, *new_tio;
    //Linked list env
    llenv_s **env_ll;
    //Linked list alias
    alias_t **alias;
    //Linked list local var
    lvar_t **vars_ll;
    //Linked list history
    history_t **history;
    //command struct
    command_t  *operator;
    //command
    char ***commands;
    char *parenthesis;
    char **shell_array;
    //operators return values
    int res_fork;
    int status;
    //nbr pipes
    int num_pipes;
} global_t;

//src/FORK/sh_loop.c
int forking(global_t *sh);

//src/OPERATORS/and_op.c
void my_operator(global_t *sh);
int is_operator(char **shell_array);

//src/OPERATORS/op_error.c
int and_error(global_t *sh);
int or_error(char **result);

//src/OPERATORS/or_operator.c
int or_operator(global_t *sh);

//src/OPERATORS/and_operator.c
int and_operator(global_t *sh);

//src/FORK/fork_error.c
int command_error_pipes(char *path);
int command_error(char *path);
int archi_error(char *path);
int access_exec(char *path);

//lib/add_content_to_file.c
void add_to_file(char *line, llenv_s **env_ll, char *var);

//src/FORK/parse_path.c
char *create_path(char **shell_array, llenv_s *env_ll);
char *check_path(char **path_array, char *shell_line);
int is_real(char *path);
char **parse_path(llenv_s **env);
char *find_path(llenv_s **env);

//lib/load_file.c
char **load_file(char *script_path);
char **load_file_line(char *script_path);

//src/LINKED_LIST/backup_list.c
//void add_list(head_t **head, void *data);
//void init_list(head_t **head, void *data);
//void load_list(head_t **node);

//src/FORK/sig_handler.c
void sig_handler(int status);

//src/LINKED_LIST/env_ll.c
void create_ll(llenv_s **env_ll, char **env);
int l_env(char **env);
void push_back(llenv_s **env, char *data);
void init(llenv_s **env, char *data);

//src/LINKED_LIST/check_env.c
void check(llenv_s **env);
void add_path(llenv_s **env);
void add_pwd(llenv_s **env);
void init_ll(llenv_s **env);
char *create_var(char *value);

//src/LINKED_LIST/ll_op.c
char **my_ll_to_array(llenv_s **env);
int l_env_ll(llenv_s **env);
void delete (int pos, llenv_s **env);
void replace_ll(llenv_s **env, char *var);

//src/LINKED_LIST/alias_ll.c
void create_ll_alias(alias_t **alias, char **alias_data);
void push_back_alias(alias_t **alias, char *data, char *name);
void init_alias(alias_t **alias, char *data, char *name);

//src/sh_loop.c
void sh_loop(char *shell_line, global_t *sh);
void parse_command_line(global_t *sh, char **shell_command);
void history_add(char *shell_line, global_t *sh);

//src/my_hub.c
void hub(global_t *sh);
void exec_builtin(global_t *sh);
void parse_command(global_t *sh);
int comp(char *shell_line);

//src/BUILTIN/my_env.c
int display_env(char **shell_array, llenv_s **env);

//src/BUILTIN/my_unsetenv.c
int my_unsetenv(char **shell_array, llenv_s **env);
int comp_env(llenv_s **env_ll, char *shell_line);

//src/BUILTIN/my_setenv.c
int my_setenv(char **shell_array, llenv_s **env);
int my_strlen_var(char *str);
int check_param(char **shell_array);
int find_var(llenv_s **env, char *str);

//src/BUILTIN/setenv_error.c
int error_handling(int res);
int check_len(char **shell_array, llenv_s **env);

//src/BUILTIN/my_exit.c
int my_exit(char **shell_array, llenv_s **env);

//src/BUILTIN/my_cd.c
int cd_command(char **shell_array, llenv_s **env);
char *create_pwd_var(char *pwd, char *name);
char *get_old_pwd(llenv_s **env);
char *get_home(llenv_s **env);
int analyse_command(char **shell_array);

//src/BUILTIN/my_echo.c
int my_echo(char **shell_array, llenv_s **env_ll);
//src/PIPE/my_pipe.c
void pipe_function(global_t *sh);
void duplication(int prev_pipe, int *fd, char **env, global_t *sh);
void close_fd(int prev_pipe);
int my_pipe(global_t *sh);

//src/PIPE/my_parsing.c
char ***assemble_commandss(char **shell_array);

//src/PIPE/my_condition.c
int my_comp(char *line, char *ref);
int is_pipe(char **shell_array);
int cpt_pipe(char *line, int cpt);
int redif(char **shell_array);
int condition(char *shell_array);

//src/REDIRECTTION/my_parse.c
int parse(global_t *sh);
int comp_redir(char *shell_line);

//src/REDIRECTTION/my_redirection.c
int double_lr(global_t *sh);
int fork_pipe(char ***commands, char *res, llenv_s **env_ll);
int simple_lr(global_t *sh);
int double_rr(global_t *sh);
int simple_rr(global_t *sh);

//src/PARENTHESIS/parenthesis.c
int detect_parenthesis(char **shell_command);
char **remove_parentheses(char **shell_command);
char *add_spaces_around_parenthesis(char *line);

//src/ALIAS/init_alias_ll.c
void create_load_alias(global_t *sh, alias_t **alias);
void create_alias_var(llenv_s *env_ll);

//src/ALIAS/save_alias_file.c
void save_alias_file(global_t *sh);
void write_in_file(global_t *sh, FILE *file);

//src/ALIAS/my_alias.c
int my_unalias(global_t *sh);
int my_alias(global_t *sh);
int display_alias(global_t *sh);

//src/ALIAS/parse_alias.c
void fill_alias_command(global_t *sh, int pos);
int check_alias(global_t *sh);
int check_alias_var(char *val, global_t *sh);
char *replace_alias_str(global_t *sh, int pos);

//src/HISTORY/init_history.c
void create_history_var(llenv_s *env_ll);

//src/main.c
global_t *getstruct(void);

//src/end_prog.c
void handle_signal(int signal);
void end_prog(global_t *sh);

//src/FORK//check_arg_command.c
char **check_param_array(global_t *sh);

//src/FORK/comparison.c
int check_dquotes(char *str, global_t *sh);
int contain_dollar(char *str);

//src/REPEAT/my_repeat.c
int my_repeat(global_t *sh);

//src/WHERE/my_where.c
int my_where(global_t *sh);
int follow(int *tmp, global_t *sh, int i);
int is_builtin(char *command, int *tmp);

//src/WHICH/my_which.c
int my_which(global_t *sh);

//src/LOCAL_VARIABLES/init_varll.c
void print_vars(lvar_t *vars);
int err_var(char *name);

//src/LOCAL_VARIABLES/my_set.c
int my_set(global_t *sh);
void init_lvarll(lvar_t **vars_ll, char *name, char *value);

//src/LOCAL_VARIABLES/my_unset.c
int my_unset(global_t *sh);

//src/TERMIOS/line_move.c
void character_input(char c, char *shell_line, int *index);
void backspace(char *shell_line, int *index);
void down_arrow(history_t **hist, char **line, int *index, int *init);
void up_arrow(history_t **hist, char **line, int *index, int *init);

//src/TERMIOS/hub_termios.c
void handle_arrow_keys(history_t **hist, char **line, int *index, int *init);
int handle_input(char *shell_line, global_t *sh);

//src/HISTORY/history_ll.c
void add_list_history(history_t **head, void *data, int *index, char *time_str);
int my_history(global_t *sh);
int len_list(history_t **history);
void create_load_history(global_t *sh, history_t **history);

//src/HISTORY/my_bang.c
int find_or_not(global_t *sh, history_t *curr, char *res, int found);
char *bang_command(char *res, history_t *curr, int *found);
char *bang_bang(char *res, history_t *curr, int *found);
char *bang_number(history_t *curr, char *res, int *found);

//src/HISTORY/bang.c
int bang(global_t *sh);
void add_to_history_file(global_t *sh, llenv_s **env_ll);

#endif //B_PSU_200_NCE_2_1_42SH_MATHIS_GHERI_MINISHELL_H
