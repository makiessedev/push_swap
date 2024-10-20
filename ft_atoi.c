/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorais <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 07:38:12 by mmorais           #+#    #+#             */
/*   Updated: 2024/10/20 08:00:24 by mmorais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_input(const char **str, int *sign)
{
	while (**str == ' ' || **str == '\t' || **str == '\n' || **str == '\f'
		|| **str == '\v' || **str == '\r')
		(*str)++;
	if (**str == '-')
	{
		*sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
}

long int	convert_to_number(const char *str, int sign)
{
	long int	i;

	i = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (ATOI_INDICATOR_ERROR);
		i = i * 10 + (*str - '0');
		if ((sign * i) > 2147483647 || (sign * i) < -2147483648)
			return (ATOI_INDICATOR_ERROR);
		str++;
	}
	return (sign * i);
}

long int	ft_atoi(const char *str)
{
	long int	nbr;
	int			sign;

	sign = 1;
	process_input(&str, &sign);
	if ((*str == '-' || *str == '+') && !*(str + 1))
		return (ATOI_INDICATOR_ERROR);
	nbr = convert_to_number(str, sign);
	return (nbr);
}
