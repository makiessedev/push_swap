/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   very_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorais <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 06:26:44 by mmorais           #+#    #+#             */
/*   Updated: 2024/10/20 07:27:27 by mmorais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_each_value(char **nbrs)
{
	char	**splited;
	int		total_count;
	int		i;
	int		j;

	total_count = 0;
	i = 1;
	while (nbrs[i])
	{
		splited = ft_split(nbrs[i], ' ');
		j = 0;
		while (splited[j])
		{
			total_count++;
			j++;
		}
		ft_freestr(splited);
		free(splited);
		i++;
	}
	return (total_count);
}

int	ft_store_numbers(char **splited, char **nbrs, int aux, int nbrs_size)
{
	int	j;

	j = 0;
	while (splited[j])
	{
		if (aux < nbrs_size)
			nbrs[aux++] = ft_strdup(splited[j]);
		else
			break ;
		j++;
	}
	return (aux);
}

char	**ft_get_each_nbr(char **av, char **numbers, int nbrs_size)
{
	t_loop_vars		loop;
	char			**splited;

	loop.aux = 0;
	loop.i = 1;
	numbers = malloc(sizeof(char *) * (nbrs_size + 1));
	if (!numbers)
		return (NULL);
	while (av[loop.i] && loop.aux < nbrs_size)
	{
		splited = ft_split(av[loop.i], ' ');
		if (!splited)
		{
			free(numbers);
			return (NULL);
		}
		loop.aux = ft_store_numbers(splited, numbers, loop.aux, nbrs_size);
		ft_freestr(splited);
		free(splited);
		loop.i++;
	}
	numbers[loop.aux] = NULL;
	return (numbers);
}
