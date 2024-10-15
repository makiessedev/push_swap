#include "push_swap.h"

int ft_verify_repeat(t_node *list, int n)
{
    while (list)
    {
        if (list->data == n)
            return (0);
        list = list->next; 
    }
    return (1);
}

static int ft_handle_very_val_on_very_arg(char **nbrs, t_node **list)
{
    int total_count = 0;
    char **numbers;

    total_count = count_each_value(nbrs);
    numbers = NULL;
    numbers = get_each_nbr(nbrs, numbers, total_count);
    

    while (--total_count >= 0)
    {
        if (!ft_verify_digit(numbers[total_count]))
            return (0);
        if (!ft_verify_min_or_max_int(ft_atoi(numbers[total_count])))
            return (0);
        if (!ft_verify_repeat(*list, ft_atoi(numbers[total_count])))
            return (0);
        ft_add_on_stack(list, ft_atoi(numbers[total_count]));
    }
    return (1);
}

static int ft_handle_very_val_on_one_arg(char **nbrs, int i, t_node **list)
{
    while (i-- > 0)
    {
        if (!ft_verify_digit(nbrs[i]))
            return (0);
        if (!ft_verify_min_or_max_int(ft_atoi(nbrs[i])))
            return (0);
        if (!ft_verify_repeat(*list, ft_atoi(nbrs[i])))
            return (0);
        ft_add_on_stack(list, ft_atoi(nbrs[i]));
    }
    return (1);
}

static void ft_handle_unique_val_on_str(char **nbrs)
{
    if (!(ft_verify_digit(nbrs[0])))
    {
        ft_free_mat(nbrs);
        ft_print_error_end_exit();
    }
    if (!ft_verify_min_or_max_int(ft_atoi(nbrs[0])))
    {
        ft_free_mat(nbrs);
        ft_print_error_end_exit();
    }
    ft_free_mat(nbrs);
    exit(0);
} 

int ft_check_and_init_stack(int ac, char **av, t_node **stack)
{
    char    **nbrs;
    int i;

    if (ac == 2)
    {
        nbrs = ft_split(av[1], ' ');
        i = ft_array_len(nbrs);
        if (i == 0)
            return (ft_free_mat(nbrs), 0);
        else if (i == 1)
            ft_handle_unique_val_on_str(nbrs);
        else if (!ft_handle_very_val_on_one_arg(nbrs, i, stack))
        {
            ft_free_mat(nbrs);
            ft_free_stack(*stack);
            write(1, "Error\n", 6);
            return (0);
        }
        ft_free_mat(nbrs);
    }
    else if (ac > 2)
    {
        if (!ft_handle_very_val_on_very_arg(av, stack))
        {
            ft_free_stack(*stack);
            ft_print_error_end_exit();
        }
    }
    if (ft_verify_already_sorted(*stack))
        return (ft_free_stack(*stack), 0);
    return (1);
}