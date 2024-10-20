/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorais <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 07:19:16 by mmorais           #+#    #+#             */
/*   Updated: 2024/10/20 07:19:18 by mmorais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

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
