#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_validate_and_init_stack(argc, argv);
	if (!a || ft_check_dup(a))
	{
		ft_free(&a);
		ft_print_error_and_exit();
	}
	if (!ft_check_already_sort(a))
		ft_sort_stack(&a);
	ft_free(&a);
	return (0);
}
