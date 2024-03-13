##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## printf
##

NAME    =    libmy.a

SRC        = display.c\
			display2.c\
			display3.c\
			my_compute_power_rec.c\
			my_getnbr.c\
			my_printf.c\
			my_put_float.c\
			my_put_floathex.c\
			my_put_floatsc.c\
			my_put_floatscupp.c\
			my_put_nbr.c\
			my_put_uns.c\
			my_putchar.c\
			my_putnbr_base.c\
			my_putstr.c\
			my_str_isprintable.c\
			my_strlen.c\
			my_strprint.c


OBJ        =    $(SRC:.c=.o)

all:    $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
	rm -f *~
	rm -rf coding-style-reports.log
	rm -rf $(NAME)

fclean: clean

re:    fclean all
