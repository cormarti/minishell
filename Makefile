# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cormarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/10 05:21:08 by cormarti          #+#    #+#              #
#    Updated: 2018/03/25 15:25:45 by cormarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIB = libft.a

FLAGS = -Wall -Werror -Wextra -g

SRCS = 	minishell.c get_next_line.c env.c ft_split_whitespaces.c builtins.c \
		setenv.c unsetenv.c exit.c cd.c echo.c system.c

SRCSPATH = $(addprefix Srcs/,$(SRCS))

OBJ = $(SRCSPATH:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@+$(MAKE) -C libft/
		@gcc $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

%.o: %.c
		@gcc $(FLAGS) -c $< -I Includes/ -o $@

clean:
		@+$(MAKE) -C libft/ clean
		@/bin/rm -rf $(OBJ)

srclean:
		@/bin/rm -rf $(OBJ)

fclean: clean
		@+$(MAKE) -C libft/ fclean
		@/bin/rm -rf $(NAME)

re: fclean all
