#include "push_swap.h"

void    ft_set_targets(t_vars *vars, t_target *target_data, t_node **a, t_node **b)
{
    if (vars->stack_a + vars->stack_b < vars->cheapest_nbr)
    {
        vars->cheapest_nbr = vars->stack_a + vars->stack_b;
        target_data->a_value = vars->a_value;
        target_data->direction_a = vars->direction_a;
        target_data->b_value = vars->b_value;
        target_data->direction_b = vars->direction_b;
    }
    if (ft_operation_nbrs(vars->b_value, a, b, 1) < vars->cheapest_nbr)
    {
        vars->cheapest_nbr = ft_operation_nbrs(vars->b_value, a, b, 1);
        target_data->a_value = vars->a_value;
        target_data->direction_a = 1;
        target_data->b_value = vars->b_value;
        target_data->direction_b = 1;
    }
    if (ft_operation_nbrs(vars->b_value, a, b, -1) < vars->cheapest_nbr)
    {
        vars->cheapest_nbr = ft_operation_nbrs(vars->b_value, a, b, -1);
        target_data->a_value = vars->a_value;
        target_data->direction_a = -1;
        target_data->b_value = vars->b_value;
        target_data->direction_b = -1;
    }
}

t_target    ft_update_targets(t_node **a, t_node **b)
{
    t_node  *tmp;
    t_target    target_data;
    t_vars  vars;

    vars.b_index = 0;
    vars.cheapest_nbr = INT_MAX;
    tmp = (*b);
    while (tmp)
    {
        vars.a_value = ft_find_target(a, tmp->data);
        vars.a_index  = ft_find_index(*a, vars.a_value);
        ft_set_direction(a, b, &vars);
        vars.b_value = tmp->data;
        ft_set_targets(&vars, &target_data, a, b);
        tmp = tmp->next;
        vars.b_index++;
    }
    return (target_data);
}

void    ft_rrr_or_rr(t_node **a, t_node **b, t_target target_data)
{
    while ((*b)->data != target_data.b_value && (*a)->data != target_data.a_value)
    {
        if (target_data.direction_b == -1)
            ft_rr(a, b);
        else
            ft_rrr(a, b);
    }
}

void    ft_order_b_and_push_to_a(t_node **a, t_node **b, t_target target_data)
{
    if (target_data.direction_a == target_data.direction_b)
        ft_rrr_or_rr(a, b, target_data);
    while ((*b)->data != target_data.b_value)
    {
        if (target_data.direction_b == -1)
            ft_rb(b, 1);
        else if (target_data.direction_b == 1)
            ft_rrb(b, 1);
    }
    while ((*a)->data != target_data.a_value)
    {
        if (target_data.direction_a == -1)
            ft_ra(a, 1);
        else if (target_data.direction_b == 1)
            ft_rra(a, 1);
    }
    ft_pa(a, b);
}

int    count_each_value(char **nbrs)
{
    char    **splited;
    int total_count;
    int i;
    int j;

    total_count = 0;
    i = 1;
    while (nbrs[i]) {
        splited = ft_split(nbrs[i], ' ');
        j = 0;
        while (splited[j]) {
            total_count++;
            j++;
        }
        ft_free_mat(splited);
        i++;
    }
    return (total_count);
}