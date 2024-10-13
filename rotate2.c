#include "push_swap.h"

void    ft_rrr(t_node *a, t_node *b)
{
    ft_rra(a, 0);
    ft_rrb(b, 0);
    write(1, "rrr\n", 4);
}

void    ft_rr(t_node *a, t_node *b)
{
    ft_ra(a, 0);
    ft_rb(b, 0);
    write(1, "rr\n", 3);
}