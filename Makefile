NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

SRC =	push_swap.c \
		ft_validate_and_init_stack.c \
		ft_stack_new.c \
		solver_utils_ab.c \
		solver_utils_ba.c \
		ft_rotate_and_push.c \
		operations.c \
		operations_2.c \
		operations_3.c \
		lst_utils.c \
		lst_utils_2.c \
		ft_sort_big.c \
		ft_sort_three.c \
		ft_check_best_rotate.c \
		ft_split.c \
		utils.c

OBJ = ${SRC:.c=.o}

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: clean all

.PHONY: all clean fclean re