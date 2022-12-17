# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 13:04:02 by abourkab          #+#    #+#              #
#    Updated: 2022/12/17 23:13:14 by abourkab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	= main.c \
		input_check.c input_check_utils.c \
		stack_to_stack_one.c \
		stack_to_stack_two.c \
		swap.c push.c rotate.c reverse_rotate.c \
		sort_tiny.c\
		stack.c fill.c \
		utils.c ft_split.c sort.c sort_prime.c\

OBJS	= $(SRCS:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
