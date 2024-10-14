#include "push_swap.h"

void    ft_add_on_stack(t_node *stack, int value)
{
    t_node  *node;

    node = malloc(sizeof(t_node));
    if (node == NULL)
        return ;
    node->data = value;
    node->next = stack;
    stack = node;
}

int main(int ac, char **av)
{
    t_node  *stack_a;
    t_node  *stack_b;

    if (ac == 1)
        return (0);
    stack_a = NULL;
    stack_b = NULL;
    if (!ft_check_and_init_stack(ac, av, stack_a))
        return (0);
    if (ft_stack_size(stack_a) == 2)
        ft_sort_2(stack_a);
    else if (ft_stack_size(stack_a) == 3)
        ft_sort_3(stack_a);
    else
        ft_turk(stack_a, stack_b);
    ft_free_stack(stack_a);
    ft_free_stack(stack_b);
    return (0);
}