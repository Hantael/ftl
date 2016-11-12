##
## Makefile for Makefile in /home/hantael/Rendu/PSU_2014_my_ls
##
## Made by Marine Morard
## Login   <morard_m@epitech.net>
##
## Started on  Thu Nov 27 16:09:33 2014 Marine Morard
## Last update Sat Nov 12 09:15:49 2016 MORARD Marine
##

NAME	= my_ftl

SRCS	= air_shed.c \
	  my_string.c \
	  container.c \
	  system_control.c \
	  system_repair.c \
	  readline.c \
	  main.c \
	  game.c \
	  affichage.c \
	  action.c \
	  check.c \
	  help.c

CC	= gcc

CD	= cd

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror -ansi -pedantic -I.

LINK_LIB = lib/my/

MAKELIB	= make

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(SRCS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
