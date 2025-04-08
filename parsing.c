/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:32:12 by rimagalh          #+#    #+#             */
/*   Updated: 2025/04/07 15:32:12 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_atol(char *str)
{
	int		i;
	int		neg;
	long	res;

	i = -1;
	neg = 1;
	res = 0;
	if (str[++i] == '-')
		neg *= -1;
	if (str[i] == '+' && str[i - 1] != '+' && str[i - 1] != '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += (str[i] - 48);
		i++;
	}
	return (res * neg);
}

int	ft_valid_input(int ac, char **av)
{
	int		i;
	long	res;

	i = ac - 1;
	if (ft_atol(av[1]) > 200)
		return (0);
	if (ac == 6 && ft_atol(av[5]) < 0)
		return (0);
	while (i > 0)
	{
		if (!ft_isnumber(av[i]))
			return (0);
		i--;
	}
	i = 4;
	while (i > 0)
	{
		res = ft_atol(av[i]);
		if (res <= 0)
			return (0);
		if (res > INT_MAX)
			return (0);
		i--;
	}
	return (1);
}
