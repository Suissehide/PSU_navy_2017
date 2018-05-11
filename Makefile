##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

SRC=		src/board.c			\
		src/error_map.c			\
		src/get_next_line.c		\
		src/init_navy.c			\
		src/main.c			\
		src/game.c			\
		src/navy.c			\
		src/navy_connection.c		\
		src/navy_convert.c		\
		src/navy_src2.c			\
		src/navy_src.c			\
		src/navy_wait.c			\
		src/receive.c			\
		src/send.c			\
		src/verif_ships.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include
CFLAGS	+=	-Wall -Wextra

NAME	=	navy

all:		$(NAME) clean

$(NAME):	$(OBJ)
		@echo "OBJ files created"
		@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		@echo "$(NAME) compiled"

tests_run:
		make -C ./tests/
clean:
		@$(RM) $(OBJ)
		@echo "OBJ files removed"

fclean:
		@$(RM) $(NAME)
		@echo "Binary file removed"

re:		fclean all

.PHONY:		all clean fclean re
