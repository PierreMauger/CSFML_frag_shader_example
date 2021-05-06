##
## SHADER_VIEWER PROJECT
## May 2021
## File description:
## Main Makefile
##

SRC 			=

SRC				+=	main.c

NAME			=	shader

OBJ				=	$(SRC:.c=.o)

CFLAGS			=	-L lib/blib -I include -lblib -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm -Wall -Wextra -W

CFLAGS_DEBUG	=	-g

$(NAME):	$(OBJ)
	@make -C lib/blib
	@(gcc $(OBJ) -o $(NAME) $(CFLAGS)) > /dev/null

all:	$(NAME)

clean:
	@(make clean -C lib/blib) > /dev/null
	@(rm -f $(OBJ)) > /dev/null
	@find . -name "*.gcno" -delete
	@find . -name "*.gcda" -delete
	@find . -name "*.o" -delete

fclean:	clean
	@(make fclean -C lib/blib) > /dev/null
	@(rm -f $(NAME)) > /dev/null

re:	fclean all

debug:
	gcc $(SRC) -o $(NAME) $(CFLAGS) $(CFLAGS_DEBUG)
