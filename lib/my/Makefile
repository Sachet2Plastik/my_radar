##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC	=	*.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

DUP	=	*~

all:	$(NAME) clean

$(NAME):	$(OBJ)
	gcc -c *.c
	rm -f '*.o'
	ar rc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f $(DUP)

re:	fclean all
