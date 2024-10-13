#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct  s_node
{
    int data;
    struct t_node *next;
}   t_node;

typedef struct s_target
{
    int a_value;
    int b_value;
    int direction_a;
    int direction_b;
}   t_target;

typedef struct s_vars
{
    long int    n_plus_b;
    int stack_a;
    int stacl_b;
    int direction_a;
    int direction_b;
    int a_index;
    int b_index;
    int value;
    int arg;

}   t_vars;

/* util.c */
t_node  *ft_get_stack_first(t_node *node);
t_node  *ft_get_stack_last(t_node *node);


/* swap.c */
void    ft_sa(t_node *a, int flag);
void    ft_sb(t_node *b, int flag);
void    ft_ss(t_node *a, t_node *b);

/* rotate.c */
void    ft_ra(t_node *a, int flag);
void    ft_rb(t_node *b, int flag);
void    ft_rra(t_node *a, int flag);
void    ft_rrb(t_node *b, int flag);

/* rotate2.c */
void    ft_rrr(t_node *a, t_node *b);
void    ft_rr(t_node *a, t_node *b);

/* utils.c */
t_node  *ft_get_stack_first(t_node *node);
t_node  *ft_get_stack_last(t_node *node);
int ft_array_len(char **array);
int ft_verify_digit(char *s);
int ft_verify_already_sorted(t_node *stack);

/* utils2.c */
int ft_verify_min_or_max_int(int n);
int ft_get_max_stack(t_node *stack);
int ft_get_min_stack(t_node *stack);
int ft_stack_size(t_node *stack);

/* push_swap.c */
void    ft_add_on_stack(t_node *stack, int value);

/* free_and_exit.c */
void    ft_print_error_end_exit();
void    ft_free_mat(char **mat);
void    ft_free_stack(t_node *stack);

/* check.c */
int ft_check_and_init_stack(int ac, char **av, t_node *stack);

/* sort_2_and_3.c */
void ft_sort_2(t_node *stack);
void ft_sort_3(t_node *stack);

/* push.c */
void    ft_pb(t_node *a, t_node *b);
void    ft_pa(t_node *a, t_node *b);

# endif