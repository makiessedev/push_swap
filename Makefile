NAME = push_swap
C_FILES = main.c stack.c
OBJ = $(FILES:.c=.o)
CC = cc
C_FLAGS = -Wall -Wextra -Werror -fsanitize=address -g

$(NAME): $(C_FILES)
	@$(CC) $(FLAGS) $(C_FILES) -o $(NAME)

all: $(NAME)

run: all
	@./$(NAME)
