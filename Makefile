##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	./src/check.c \
		./src/display.c \
		./src/engine.c \
		./src/instances.c \
		./src/main.c \
		./src/math.c \
		./src/reader.c \
		./src/string.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Werror -Wextra -pedantic -std=c99 \
		-I include -ggdb3 -O0

LDFLAGS	+=	-lm

NAME	=	109titration

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
