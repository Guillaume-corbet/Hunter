##
## EPITECH PROJECT, 2018
## Evalexpr
## File description:
## Makefile
##

SRC		=	main.c		\
			easy_mode1.c		\
			easy_mode2.c		\
			easy_mode3.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_hunter

all:	clean fclean $(NAME)

$(NAME):
		(cd ./lib/my/ && make)
		(cd ./lib/my_printf/ && make)
		gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-system -lcsfml-audio -L./lib/my/. -lmy -L./lib/my_printf/. -lmy_printf

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)

re:
		fclean $(NAME)

auteur:
		echo $(USER) > auteur
