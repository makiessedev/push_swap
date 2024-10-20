/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_and_init_stack.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorais <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 07:20:58 by mmorais           #+#    #+#             */
/*   Updated: 2024/10/20 08:25:49 by mmorais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_case_unique_string(char **argv)
{
	long int	j;
	int			i;
	t_stack		*a;
	char		**tmp;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi(tmp[i]);
		if (j == ATOI_INDICATOR_ERROR)
		{
			ft_freestr(tmp);
			free(tmp);
			ft_free(&a);
			ft_print_error_and_exit();
		}
		ft_add_back(&a, ft_stack_new(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}

static void	ft_validate_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		exit(1);
	if (argc == 2)
		return ;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0 || ft_is_only_space(argv[i]))
			ft_print_error_and_exit();
		i++;
	}
}

static char	**ft_prepare_numbers(int argc, char **argv, int *total_count)
{
	char	**nbrs;

	*total_count = ft_count_each_value(argv);
	nbrs = ft_get_each_nbr(argv, NULL, *total_count);
	return (nbrs);
}

t_stack	*ft_process_numbers(char **nbrs, int total_count)
{
	long int	j;
	int			i;
	t_stack		*a;

	i = 0;
	a = NULL;
	while (i < total_count)
	{
		j = ft_atoi(nbrs[i]);
		if (j == ATOI_INDICATOR_ERROR)
		{
			ft_freestr(nbrs);
			free(nbrs);
			ft_free(&a);
			ft_print_error_and_exit();
		}
		ft_add_back(&a, ft_stack_new(j));
		i++;
	}
	return (a);
}

t_stack	*ft_validate_and_init_stack(int argc, char **argv)
{
	t_stack		*a;
	char		**nbrs;
	int			total_count;

	a = NULL;
	ft_validate_args(argc, argv);
	if (argc == 2)
	{
		a = ft_case_unique_string(argv);
		return (a);
	}
	nbrs = ft_prepare_numbers(argc, argv, &total_count);
	a = ft_process_numbers(nbrs, total_count);
	ft_freestr(nbrs);
	free(nbrs);
	return (a);
}
