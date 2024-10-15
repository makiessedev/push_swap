#include "push_swap.h"

int ft_verify_min_or_max_int(int n)
{
    if (n > INT_MAX || n < INT_MIN)
        return (0);
    return (1);
}

int ft_get_max_stack(t_node *stack)
{
    int tmp;

    tmp = stack->data;
    while (stack)
    {
        if (stack->data > tmp)
            tmp = stack->data;
        stack = stack->next;
    }
    return (tmp);
}

int ft_get_min_stack(t_node *stack)
{
    int tmp;

    tmp = ft_get_max_stack(stack);
    while (stack)
    {
        if (!(stack->data > tmp))
            tmp = stack->data;
        stack = stack->next; 
    }
    return (tmp);
}

int ft_stack_size(t_node *stack)
{
    int i;

    i = 0;
    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return (i);
}

void    ft_put_min_on_top(t_node **stack)
{
    int min;
    int direction;
    int index;

    min = ft_get_min_stack(*stack);
    index = ft_find_index(*stack, min);
    if (index <= ft_stack_size(*stack) / 2)
        direction = -1;
    else if (index > ft_stack_size(*stack) / 2)
        direction = 1;
    while ((*stack)->data != min)
    {
        if (direction == -1)
            ft_ra(stack, 1);
        else if (direction == 1)
            ft_rra(stack, 1);
    }
}