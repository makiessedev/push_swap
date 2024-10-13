#include "push_swap.h"

void    ft_sa(t_node *a, int flag)
{
    t_node  *link1;
    t_node  *link2;
    t_node  *link3;

    if (a == NULL)
        return ;
    link1 = a;
    link2 = link1->next;
    link3 = link2->next;
    link2->next = link1;
    link1->next = link3;
    a = link2;
    if (flag == 1)
        write(1, "sa\n", 3);
}

void    ft_sb(t_node *b, int flag)
{
    t_node  *link1;
    t_node  *link2;
    t_node  *link3;

    if (b == NULL)
        return ;
    link1 = b;
    link2 = link1->next;
    link3 = link2->next;
    link2->next = link1;
    link1->next = link3;
    b = link2;
    if (flag == 1)
        write(1, "sb\n", 3);
}

void    ft_ss(t_node *a, t_node *b)
{
    ft_sa(a, 0);
    ft_sb(b, 0);
    write(1, "ss\n", 3);
}