##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile My LIB
##

SRC = *.c \
	  lists/*.c

OBJ = *.o

NAME = libmy.a

all:
	gcc -c $(SRC) -Wall -Wextra -I lists/
	ar rc $(NAME) *.o
	cp my.h ../../includes/
	cp lists/mylist.h ../../includes/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean	all
