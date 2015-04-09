##
## Makefile for  in /home/garrig_b/KART/new
## 
## Made by a
## Login   <garrig_b@epitech.net>
## 
## Started on  Sun Oct 26 11:33:44 2014 a
## Last update Sun Oct 26 22:23:08 2014 a
##

NAME	= bin/MarioKart

SRC     = sources/aff.c \
	sources/init.c \
	sources/main.c \
	sources/move.c \
	sources/tools.c \
	sources/random.c \
	sources/random2.c \
	sources/detail.c \
	sources/collision.c \
	sources/bug.c \
	sources/brain.c \
	sources/object.c \



RM	= rm -f
OBJ	= $(SRC:.c=.o)
CC	= cc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lncurses

	@(clear)
	@echo '          _____       ____   '
	@echo '        .~     ~.__  |    |  '
	@echo '      @@@@         ~. |¯¯|   '
	@echo '     .-.@@¯¯¯|¯|¯¯¯¯¯\|  |   '
	@echo '     ~-~ @@  |_|@     )  /   '
	@echo '       \ @@    @@@@@@@@ /    '
	@echo '      __\____   ____.~ /     '
	@echo '     /   \  \\___\\__ ~      '
	@echo '     \___/__/ o  o   /¯¯\    '
	@echo '      /¯¯\       __ /   /    '
	@echo '     /   /   .-~¯  ¯\__/     '
	@echo '     \__/-.-~                '
	@echo '	                            '
	@echo ' MARIO KART : RETARD EDITION ©'
	@echo '                              '

clean:
	$(RM) $(OBJ) *\# .*\# *~ .*~ *core*

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
