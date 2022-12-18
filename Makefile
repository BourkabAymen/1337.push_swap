# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourkab <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 22:20:57 by abourkab          #+#    #+#              #
#    Updated: 2022/12/18 22:21:06 by abourkab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c utiles_part_one.c check_error.c operations.c \
	operations2.c function_3_4_5.c index.c utiles_part_two.c \
	big_sort_function_one.c \
	big_sort_function_two.c big_sort_function_utiles.c \

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
