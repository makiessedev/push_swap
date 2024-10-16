#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int				sign;
	long long int	i;

	i = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+' && !*(str + 1))
		ft_print_error_and_exit();
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_print_error_and_exit();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((sign * i) > 2147483647 || (sign * i) < -2147483648)
		ft_print_error_and_exit();
	return (sign * i);
}

static t_stack	*ft_case_unique_string(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi(tmp[i]);
		ft_add_back(&a, ft_stack_new(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}

t_stack	*ft_validate_and_init_stack(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;
	int	total_count;
	char **nbrs;

	i = 0;
	a = NULL;
	if (argc < 2)
		ft_print_error_and_exit();
	if (argc == 2)
		a = ft_case_unique_string(argv);
	else
	{
		total_count = ft_count_each_value(argv);
		nbrs = ft_get_each_nbr(argv, nbrs, total_count);
		while (i < total_count)
		{
			j = ft_atoi(nbrs[i]);
			ft_add_back(&a, ft_stack_new(j));
			i++;
		}
	}
	return (a);
}
