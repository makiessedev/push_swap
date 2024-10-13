#include "push_swap.c"

void    ft_print_error_end_exit()
{
    write(1, "Error\n", 6);
    exit(1);
}

void    ft_free_mat(char **mat)
{
    int i;

    i = -1;
    while (mat[++i])
        free(mat[i]);
    free(mat);
}

void    ft_free_stack(t_node *stack)
{
    t_node  *current;
    t_node  *next;

    current = stack;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}