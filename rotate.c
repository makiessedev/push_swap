#include "push_swap.h"

void    ft_ra(t_node **a, int flag)
{
    t_node  *first;
    t_node  *last;

    if (*a == NULL)
        return ;
    first = ft_get_stack_first(*a);
    last = ft_get_stack_last(*a);
    *a = (*a)->next;
    last->next = first;
    first->next = NULL;
    if (flag == 1)
        write(1, "ra\n", 3);
}

void    ft_rb(t_node **b, int flag)
{
    t_node  *first;
    t_node  *last;

    if (*b == NULL)
        return ;
    first = ft_get_stack_first(*b);
    last = ft_get_stack_last(*b);
    *b = (*b)->next;
    last->next = first;
    first->next = NULL;
    if (flag == 1)
        write(1, "rb\n", 3);
}

void    ft_rra(t_node **a, int flag)
{
    t_node  *first;
    t_node  *last;

    if (*a == NULL)
        return ;
    last = ft_get_stack_last(*a);
    first = ft_get_stack_first(*a);
    while (first->next != last)
        first = first->next;
    first->next = NULL;
    last->next = *a;
    *a = last;
    if (flag == 1)
        write(1, "rra\n", 4);
}

void    ft_rrb(t_node **b, int flag)
{
    t_node  *first;
    t_node  *last;

    if (*b == NULL)
        return ;
    last = ft_get_stack_last(*b);
    first = ft_get_stack_first(*b);
    while (first->next != last)
        first = first->next;
    first->next = NULL;
    last->next = *b;
    *b = last;
    if (flag == 1)
        write(1, "rrb\n", 4);
}