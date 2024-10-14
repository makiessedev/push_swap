NAME = push_swap
C_FILES = check.c free_and_exit.c push_swap.c \
			push.c rotate.c rotate2.c sort_2_and_3.c \
			swap.c turk_aux.c turk.c utils.c utils2.c
OBJ = $(C_FILES:.c=.o)
LIBFT = ./libft
CC = cc
C_FLAGS = -Wall -Wextra -Werror -fsanitize=address -g

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT)

$(NAME): $(OBJ)
	$(CC) $(C_FLAGS) $(OBJ) -o $(NAME) -L$(LIBFT) -lft

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT)

re:
	fclean all
	make re -C $(LIBFT)

.PHONY: all clean fclean re