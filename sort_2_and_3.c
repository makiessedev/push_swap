#include "push_swap.h"

void ft_sort_2(t_node *stack)
{
    if (!ft_verify_already_sorted(stack))
        ft_sa(stack, 1);
}

void ft_sort_3(t_node *stack)
{
    t_node  *middle_node;
    if (ft_get_min_stack(stack) == stack->data)
    {
        ft_rra(stack, 1);
        ft_sa(stack, 1);
    }
    else if (ft_get_max_stack(stack) == stack->data)
    {
        ft_ra(stack, 1);
        if (!ft_verify_already_sorted(stack))
            ft_sa(stack, 1);
    }
    else
    {
        middle_node = stack->next;
        if (ft_get_min_stack(stack) == middle_node->data)
            ft_sa(stack, 1);
        else
            ft_rra(stack, 1);
    }
}