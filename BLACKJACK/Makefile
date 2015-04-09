##
## Makefile for  in /home/garrig_b/BLACKJACK
## 
## Made by a
## Login   <garrig_b@epitech.net>
## 
## Started on  Sun Aug 17 16:34:53 2014 a
## Last update Tue Aug 26 13:21:25 2014 a
##

NAME	= Magic21

SRC	= main.c \
	  fonct.c \
	interface.c \
	card.c \
	cards.c \
	dealer.c \
	win_loose.c \
	check_card.c \

CC	= cc

RM	= rm -f

OBJ     = $(SRC:.c=.o)

CFLAGS  = -lncurses


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ)  -o $(NAME)  -lncurses $(CLFAGS)
	@(clear)
	@(./$(NAME))

clean:
	$(RM) $(OBJ) *\# .*\# *~ .*~ *core*

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
