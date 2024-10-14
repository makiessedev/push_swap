#include "push_swap.h"

// ft_case_rrr_or_rr
int ft_operation_nbrs(int   value, t_node *a, t_node *b, int direction)
{
    int target;
    int operation_nbr;

    if (direction == -1)
    {
        target = ft_find_target(a, value);
        operation_nbr = ft_find_index(b, value);
        if (ft_find_index(a, target) > operation_nbr)
            operation_nbr = ft_find_index(a, target);
    }
    if (direction == 1)
    {
        target = ft_find_target(a, value);
        operation_nbr = ft_stack_size(b) - ft_find_index(b, value);
        if (ft_stack_size(a) - ft_find_index(a, target) > operation_nbr)
            operation_nbr = ft_stack_size(a) - ft_find_index(a, target);
    }
    return (operation_nbr + 1);
}

void    ft_set_direction(t_node *a, t_node *b, t_vars *vars)
{
    if (vars->a_index <= ft_stack_size(a) / 2)
    {
        vars->stack_a = vars->a_index;
        vars->direction_a = -1;
    }
    else if (vars->a_index > ft_stack_size(a) / 2)
    {
        vars->stack_a = ft_stack_size(a) - vars->a_index;
        vars->direction_a = 1;
    }
    if (vars->b_index <= ft_stack_size(b) / 2)
    {
        vars->stack_b = vars->stack_b + 1;
        vars->direction_b = -1;
    }
    else if (vars->b_index > ft_stack_size(b) / 2)
    {
        vars->stack_b = ft_stack_size(b) - vars->a_index + 1;
        vars->direction_b = 1;
    }
}

int    ft_find_index(t_node *a, int value)
{
    int i;

    i = 0;
    while(a)
    {
        if (a->data == value)
            break ;
        a = a->next;
        i++;
    }
    return (i);
}

int    ft_find_target(t_node *a, int b)
{
    long int    best_option;
    t_node  *tmp;

    best_option = INT_MAX;
    if (b > ft_get_max_stack(a) || b < ft_get_min_stack(a))
        return (ft_get_max_stack(a));
    else
    {
        tmp = a;
        while (tmp)
        {
            if (tmp->data > b)
            {
                if (tmp->data < best_option)
                    best_option = tmp->data;
            }
            tmp = tmp->next;
        }
    }
    return (best_option);
}

void ft_turk(t_node *a, t_node *b)
{
    t_target    target_datas;

    while (ft_stack_size(a) > 3)
        ft_pb(a, b);
    if (!ft_verify_already_sorted(a))
        ft_sort_3(a);
    while (ft_stack_size(b) > 0)
    {
        target_datas = ft_update_targets(a, b);
        if (b->data > ft_get_max_stack(a) || b->data < ft_get_min_stack(a))
        {
            ft_put_min_on_top(a);
            ft_pa(a, b);
        }
        else
            ft_order_b_and_push_to_a(a, b, target_datas);
    }
    while (!ft_verify_already_sorted(a))
    {
        if (ft_find_index(a, ft_get_max_stack(a)) <= ft_stack_size(a) / 2)
            ft_ra(a, 1);
        else
            ft_rra(a, 1);       
    }
}