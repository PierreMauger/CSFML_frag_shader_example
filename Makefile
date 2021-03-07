SRC		=	main.c

NAME	=	shader

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm

CFLAGS_DEBUG=	-Wall -Wextra -W -g

$(NAME):	$(OBJ)
	@(gcc $(OBJ) -o $(NAME) $(CFLAGS)) > /dev/null

all:	$(NAME)

clean:
	@(rm -f $(OBJ)) > /dev/null
	@find . -name "*.gcno" -delete
	@find . -name "*.gcda" -delete
	@find . -name "*.o" -delete

fclean:	clean
	@(rm -f $(NAME)) > /dev/null

re:	fclean all

debug:
	gcc $(SRC) -o $(NAME) $(CFLAGS) $(CFLAGS_DEBUG)
