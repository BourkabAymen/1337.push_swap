# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 22:20:57 by abourkab          #+#    #+#              #
#    Updated: 2022/12/21 15:46:19 by abourkab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c \
	functions_input_check.c functions_input_check_utils.c \
	functions_initialization.c \
	functions_stack.c \
	functions_swap.c functions_push.c functions_rotate.c \
	functions_reverse_rotate.c \
	functions_sort_tiny.c functions_sort.c \
	functions_position.c functions_cost.c functions_do_move.c \
	functions_utils.c
CC = cc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
