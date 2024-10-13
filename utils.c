#include "push_swap.h"

t_node  *ft_get_stack_first(t_node *node)
{
    return (node);
}

t_node  *ft_get_stack_last(t_node *node)
{
    t_node  *tmp;

    while (node)
    {
        tmp = node;
        node = node->next;
    }
    return (tmp);
}

int ft_array_len(char **array)
{
    int i;

    i = 0;
    while (array[i])
        i++;
    return (i);
}

int ft_verify_digit(char *s)
{
    int i;

    i = 0;
    if (s[0] == '-' || s[0] == '+')
        i++;
    while (s[i])
    {
        if (!ft_isdigit(s[i]))
            return (0);
        i++;
    }
    return (1);
}

int ft_verify_already_sorted(t_node *stack)
{
    int tmp;

    tmp = stack->data;
    while (stack)
    {
        if (stack->data >= tmp)
            tmp = stack->data;
        else    
            return (0);
        stack = stack->next;
    }
}