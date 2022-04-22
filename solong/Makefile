# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 11:41:36 by abkasmi           #+#    #+#              #
#    Updated: 2022/03/27 15:20:35 by abkasmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = solong.c \
		parsing.c \
		get_next_line.c \
		get_next_line_utils.c \
		solong_utils.c \
		check_utils.c \
		init_window.c \
		hooks.c \
		moves.c 

OBJS = $(SRCS:.c=.o)

NAME = so_long

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Werror -Wextra
#-fsanitize=address -g3

all: $(NAME)

$(NAME) :	$(OBJS)
		$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

clean :
		$(RM) $(OBJS)

fclean : clean
			$(RM) $(NAME)

re : 	fclean all

.PHONY: all clean fclean re