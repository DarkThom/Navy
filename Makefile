##
## Makefile for  in /home/BLENEA_T/Projects/Semestre_2/PSU/PSU_2016_navy
##
## Made by Thomas BLENEAU
## Login   <BLENEA_T@epitech.net>
##
## Started on  Mon Jan 30 12:58:01 2017 Thomas BLENEAU
## Last update Thu Feb  9 11:34:29 2017 Thomas BLENEAU
##

RM	= rm -f

CC	= gcc

CFLAGS	+= -I ./include/

NAME	= navy

SRCS	= main.c \
	  ./lib/free_function.c \
	  ./lib/get_next_line.c \
	  ./lib/isnum_alpha.c \
	  ./lib/my_getnbr.c \
	  ./lib/my_put_nbr.c \
	  ./lib/my_strcmp.c \
	  ./lib/my_strdup.c \
	  .//lib/my_str_isnum.c \
	  ./lib/my_swap.c \
	  ./lib/my_tablen.c \
	  ./src/attack_client.c \
	  ./src/check_attack.c \
	  ./src/check_connection.c \
	  ./src/check_params.c \
	  ./src/check_same_boat.c \
	  ./src/client.c \
	  ./src/convert_packet.c \
	  ./src/create_tab_game.c \
	  ./src/display_game.c \
	  ./src/display_pid.c \
	  ./src/enemy_position.c \
	  ./src/find_boat_positions.c \
	  ./src/help_command.c \
	  ./src/parsing_file.c \
	  ./src/player_won.c \
	  ./src/result_attack.c \
	  ./src/send_packet.c \
	  ./src/server.c \
	  ./src/test_win.c \
	  ./src/transmit_bit.c \

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

