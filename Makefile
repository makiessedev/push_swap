NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

SRC =	push_swap.c \
		algorithm.c \
		ft_add_back.c \
		ft_stack_new.c \
		ft_check_utils.c \
		ft_parse.c \
		solver_utils_ab.c \
		solver_utils_ba.c \
		ft_rotate_and_push.c \
		operations.c \
		operations_2.c \
		operations_3.c \
		ft_check_dup.c \
		ft_check_sorted.c \
		ft_error_print.c \
		ft_free.c \
		lst_utils.c \
		lst_utils_2.c \
		ft_parse_args_quoted.c \
		ft_list_args.c \
		ft_check_args.c \
		ft_sort_big.c \
		ft_sort_three.c \
		ft_rotate_type.c \
		ft_atoi.c \
		ft_split.c \
		ft_isdigit.c \
		ft_strlen.c
			

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