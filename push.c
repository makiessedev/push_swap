#include "push_swap.h"

void    ft_pb(t_node *a, t_node *b)
{
    t_node *first;

    if (a == NULL)
        return ;
    first = ft_get_stack_first(a);
    a = a->next;
    b = first;
    write(1, "pb\n", 3);
}

void    ft_pa(t_node *a, t_node *b)
{
    t_node *first;

    if (b == NULL)
        return ;
    first = ft_get_stack_first(b);
    b = b->next;
    a = first;
    write(1, "pa\n", 3);
}