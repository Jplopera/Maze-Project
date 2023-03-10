##
## C/SDL2 Raycaster Makefile
##

SRC		=	./src/main.c	\
			./src/color.c	\
			./src/map.c     \
			./src/geometry.c\
			./src/sprites.c

NAME	=	maze

CC		=	gcc

RM		=	rm -f

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-O2 -W -Wall -Wextra -Werror -g
CFLAGS	+=	-I./hds/

LDLIBS	=	-lSDL2 -lm -lSDL2_image

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDLIBS)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
