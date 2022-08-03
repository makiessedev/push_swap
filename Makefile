# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 13:48:18 by yogun             #+#    #+#              #
#    Updated: 2022/08/03 21:38:32 by yogun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Colors

NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
OBJ_DIR = obj/
BONUS = checker
SRC_DIR = srcs/

SRC =	srcs/push_swap/push_swap.c \
		srcs/push_swap/ft_add_back.c \
		srcs/push_swap/ft_atoi.c \
		srcs/push_swap/ft_stack_new.c \
		srcs/push_swap/ft_list_args.c \
		srcs/push_swap/ft_error_print.c \
		srcs/push_swap/ft_check_args.c \
		srcs/push_swap/operations.c \
		srcs/push_swap/operations_2.c \
		srcs/push_swap/ft_sort.c \
		srcs/push_swap/ft_sort_big.c \
		srcs/push_swap/lst_utils.c \
		srcs/push_swap/lst_utils_2.c \
		srcs/push_swap/ft_check_sorted.c \
		srcs/push_swap/ft_check_dup.c \
		srcs/push_swap/ft_free.c \
		srcs/push_swap/ft_check_utils.c \
		srcs/push_swap/ft_parse.c \
		srcs/push_swap/ft_parse_args_quoted.c \
		srcs/push_swap/ft_sort_three.c \
		srcs/push_swap/solver_utils.c \
		srcs/push_swap/solver_utils_2.c \
		srcs/push_swap/ft_print_utils.c \
		srcs/push_swap/operations_3.c \

BONUS_SRC = srcs/checker/checker.c \
			srcs/checker/checker_utils.c \
			srcs/checker/ft_checker.c \

OBJ = ${SRC:.c=.o}
BONUS_OBJ =${BONUS_SRC:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ} -o ${NAME} ${INCLUDE}

${BONUS}: ${BONUS_OBJ}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ} -o ${BONUS} ${INCLUDE}

all: ${NAME} ${BONUS}

bonus: ${BONUS} 

clean:
	${RM} ${OBJ} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus