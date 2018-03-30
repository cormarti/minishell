# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cormarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/10 05:21:08 by cormarti          #+#    #+#              #
#    Updated: 2018/03/15 00:10:26 by cormarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$NAME = minishell

$LIB = libft.a

$FLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

$SRCS = minishell.c get_next_line.c

$OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@gcc $(FLAGS) -c $(SRCS) -I Includes/
		@gcc $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

clean:
		@+$(MAKE) -C libft/ clean
		@/bin/rm -rf $(OBJ)

fclean: clean
		@+$(MAKE) -C libft/ fclean
		@/bin/rm -rf $(NAME)

re: fclean all
