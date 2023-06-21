##
## EPITECH PROJECT, 2022
## My_hunter
## File description:
## makefile
##

SRC	=	main.c	\
		error_handeling.c	\
		main_loop.c	\
		drawing_thing.c	\
		create_win.c	\
		create_linked.c	\
		moving_thing.c	\
		check_end.c	\
		event_handeling.c	\
		collide_detect.c	\
		poping_plane.c	\

OBJ	=	$(SRC:.c=.o)

COPIES	=	*~

NAME	=	my_radar

CFLAGS	=	-g -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

MAKE	=	make

all:	$(NAME)  clean

$(NAME):	$(OBJ)
	cd ./lib/my/ && $(MAKE)
	gcc -c $(SRC)
	gcc $(OBJ) -o $(NAME) -L./lib/my -lmy $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(COPIES)
	rm -f *.o

fclean:	clean
	rm -f $(NAME)
	cd lib/my/ && rm libmy.a

re:     fclean all
	rm -f $(OBJ)
