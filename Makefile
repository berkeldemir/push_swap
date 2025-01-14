CC = cc
CFLAGS = -Wall -Wextra -Werror

all:
	$(CC) $(CFLAGS) push_swap.c ft_printf.c -o push_swap

clean:
	rm push_swap

fclean: clean

re: fclean all

.PHONY: all clean fclean re