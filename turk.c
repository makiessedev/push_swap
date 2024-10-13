#include "push_swap.h"

void ft_turk(t_node *a, t_node *b)
{
    t_target    target_datas;

    while (ft_stack_size(a) > 3)
        ft_pb(a, b);
    if (!ft_verify_already_sorted(a))
        ft_sort_3(a);
    while (ft_stack_size(b) > 0)
    {
        target_datas = 
    }
}