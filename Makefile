NAME = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = push_swap.c 0_create.c 1_reduce.c 2_convert.c \
		new_atoi.c utils.c utils2.c actions_a.c actions_b.c actions_both.c \
		calc_cost_a.c calc_cost_b.c stack_utils.c stack_utils2.c sort.c big_sort.c
BONUS_SRCS = checker.c 0_create.c 1_reduce.c 2_convert.c \
			actions_a.c actions_b.c actions_both.c utils.c utils2.c new_atoi.c \
			stack_utils.c stack_utils2.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(CHECKER)

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME) $(CHECKER)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re