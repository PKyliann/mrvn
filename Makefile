##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## my_navy
##

NAME	=	42sh

SRC    =		src/sh_loop.c\
				src/BUILTIN/my_cd.c\
				src/BUILTIN/my_env.c\
				src/BUILTIN/my_exit.c\
				src/BUILTIN/my_setenv.c\
				src/BUILTIN/my_unsetenv.c\
				src/BUILTIN/setenv_error.c\
				src/FORK/fork_error.c\
				src/FORK/my_fork.c\
				src/FORK/parse_path.c\
				src/FORK/sig_handler.c\
				src/LINKED_LIST/check_env.c\
				src/LINKED_LIST/env_ll.c\
				src/LINKED_LIST/ll_op.c\
				src/PIPE/my_condition.c\
				src/PIPE/my_parsing.c\
				src/PIPE/my_pipe.c\
				src/REDIRECTION/my_parse.c\
				src/REDIRECTION/my_redirection.c\
				src/PARENTHESIS/parenthesis.c\
				lib/create_triple_array.c\
				lib/my_concat.c\
				lib/my_len.c\
				lib/my_path_array.c\
				lib/my_path_to_array.c\
				lib/my_str_to_str_array.c\
				lib/my_str_to_str_drarray.c\
				lib/str_to_array_delim.c\
				lib/my_str_to_str_parray.c\
				lib/my_str_to_str_rarray.c\
				lib/my_str_to_words_array.c\
				lib/my_strcat.c\
				lib/my_strcpm.c\
				lib/load_file.c\
				lib/add_content_to_file.c\
				lib/my_strcpy.c\
				lib/my_strdup.c\
				lib/my_strncmp.c\
				lib/path_gestion.c\
				lib/start_w_slash.c\
				lib/len_array.c\
				src/BUILTIN/my_echo.c\
				src/OPERATORS/my_operators.c\
				src/OPERATORS/operator_error.c\
				lib/my_concat_strings.c\
				lib/my_free.c\
				lib/puzzle.c\
				src/my_hub.c\
				src/ALIAS/init_alias_ll.c\
				src/LINKED_LIST/alias_ll.c\
				src/ALIAS/my_alias.c\
				src/ALIAS/save_alias_file.c\
				src/HISTORY/init_history.c\
				src/ALIAS/parse_alias.c\
				src/end_prog.c\
				lib/my_concat_array.c\
				lib/dup_array.c\
				src/FORK/check_arg_command.c\
				src/FORK/comparison.c\
				src/REPEAT/my_repeat.c\
				src/WHERE/my_where.c\
				src/WHICH/my_which.c\
				src/LOCAL_VAR/init_lvar_ll.c\
				src/LOCAL_VAR/my_set.c\
				src/LOCAL_VAR/my_unset.c\
				lib/display_array.c\
				src/HISTORY/history_ll.c\
				src/HISTORY/my_bang.c\
				src/HISTORY/bang.c\

TSRC	= 		tests/tests_shell.c\
				tests/test_setenv.c\
				tests/test_my_strncmp.c\
				tests/test_comp_commands.c\
				tests/test_error_cmd.c\
				tests/test_pipe.c\
				tests/test_redirections.c\
				tests/test_single_red.c\
				tests/test_strcpy.c\
				tests/test_strdup.c\
				tests/test_path_wslash.c\
				tests/test_pushback.c\
				tests/test_strtostr.c\
				tests/test_parentheses.c\
				tests/test_operators.c

CFLAGS	=		-W -Wall -Wextra

OBJ		=		$(SRC:.c=.o)
TOBJ	= 		$(TSRC:.c=.o)

BNAME = bonus_42

TNAME 	= tests_run

TESTNAME = unit_tests

TESTS_FLAGS =

FLAGS_TEST = --coverage -lcriterion -lgcov -fprofile-arcs -ftest-coverage

$(NAME):		$(OBJ) src/main.c
	make -C my_printf/my
	gcc -o $(NAME) $(CFLAGS) $(OBJ) src/main.c -L my_printf/my -lmy -I /include
%.o : %.c
	gcc -c $^ -o $@ $(TESTS_FLAGS)
tests_run: 		compile_test $(OBJ) $(TOBJ)
	make -C my_printf/my
	gcc -o $(TESTNAME)  $(OBJ) $(TOBJ) -L my_printf/my -lmy -I /include $(TESTS_FLAGS)
	@./$(TESTNAME)
	@gcovr --exclude tests/
compile_test:
	$(eval TESTS_FLAGS := $(FLAGS_TEST))

$(BNAME):
	make -C ./Bonus/
	mv Bonus/42sh_bonus .

bonus: $(BNAME)

all:	$(NAME)

clean:
		rm -f $(OBJ)
		rm -f $(TOBJ)
		rm -f $(NAME)
		rm -f $(TNAME)
		rm -f $(TESTNAME)
		rm -f *~
		rm -f *#
		rm -f src/*~
		rm -f src/*#
		rm -f include/*~
		rm -f include/*#
		rm -rf coding-style-reports.log
		rm -f vgcore.*
		rm -rf .idea
		rm -f prnt/my/*.o
		rm -f prnt/my/libmy.a
		rm -f lib/*.gcda
		rm -f lib/*.gcno
		rm -f src/BUILTIN/*.gcda
		rm -f src/BUILTIN/*.gcno
		rm -f src/FORK/*.gcda
		rm -f src/FORK/*.gcno
		rm -f src/LINKED_LIST/*.gcda
		rm -f src/LINKED_LIST/*.gcno
		rm -f src/OPERATORS/*.gcda
		rm -f src/OPERATORS/*.gcno
		rm -f src/PIPE/*.gcda
		rm -f src/PIPE/*.gcno
		rm -f src/REDIRECTION/*.gcda
		rm -f src/REDIRECTION/*.gcno
		rm -f src/LOCAL_VAR/*.gcda
		rm -f src/LOCAL_VAR/*.gcno
		rm -f src/ALIAS/*.gcda
		rm -f src/ALIAS/*.gcno
		rm -f src/HISTORY/*.gcda
		rm -f src/HISTORY/*.gcno
		rm -f src/PARENTHESIS/*.gcda
		rm -f src/PARENTHESIS/*.gcno
		rm -f src/REPEAT/*.gcda
		rm -f src/REPEAT/*.gcno
		rm -f src/WHICH/*.gcda
		rm -f src/WHICH/*.gcno
		rm -f src/WHERE/*.gcda
		rm -f src/WHERE/*.gcno
		rm -f src/*.gcda
		rm -f src/*.gcno
		rm -f tests/*.gcno
		rm -f tests/*.gcda
		rm -f 42sh_bonus

fclean:	clean
		rm -f $(NAME)
		make fclean -C ./Bonus
		make fclean -C my_printf/my

re: fclean  all
