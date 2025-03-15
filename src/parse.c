/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:50:13 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/15 11:55:05 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//! input
//* 0- total philos
//* 1- time to die
//* 2- time to eat
//* 3- time to sleep
//* 4- times to eat (can be 0)


static long	ft_atol(const char *nptr)
{
	long	sum;
	long	i;
	long	neg;

	if (!nptr)
		return (0);
	i = 0;
	neg = 1;
	sum = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		sum = sum * 10 + (nptr[i] - '0');
		i++;
	}
	return (sum * neg);
}

static int check_size(char *str)
{
	long n;

	n = ft_atol(str);
	if(n >= 0 && n <= INT_MAX)
		return 1;
	return 0;
}


static int validate(long *input)
{
	int i;

	i = -1;
	while(++i < 4)
		if(input[i] <= 0)
			return (0);
	if(input[4] < 0)
		return (0);
	return (1);
}

static int is_num(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	*parse_input(char **argv, t_data *data)
{
	int i;
	long *input;

	i = 0;
	input = malloc(sizeof(long) * 5);
	if (!input)
		return (NULL);
	memset(input, 0, sizeof(long) * 5);
	while(++i < 5)
	{
		if(!is_num(argv[i]) || !check_size(argv[i]))
			return (free(input), NULL);
		input[i - 1] = ft_atol(argv[i]);
	}

	if(argv[5])
		input[4] = ft_atol(argv[5]);
	else
		input[4] == NULL;

	//* probably remove this redundant check
	if(!validate(input))
		return (free(input), NULL);

	return (input);
}


