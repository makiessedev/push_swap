#include "push_swap.h"

t_stack	*ft_stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		ft_print_error_and_exit();
	new->nbr = content;
	new->next = NULL;
	return (new);
}
