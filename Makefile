NAME	= push_swap

SRCS	= src/main.c \
		src/input_check.c src/input_check_utils.c \
		src/initialization.c \
		src/stack.c \
		src/swap.c src/push.c src/rotate.c src/reverse_rotate.c \
		src/sort_tiny.c src/sort.c \
		src/position.c src/cost.c src/do_move.c \
		src/utils.c

OBJS		= $(SRCS:.c=.o)

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