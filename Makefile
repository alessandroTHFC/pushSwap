NAME = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra -Iinclude
SRCS = *.c

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
