/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:50:13 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/08 15:47:41 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//! input
//* 0- total philos
//* 1- time to die
//* 2- time to eat
//* 3- time to sleep
//* 4- times to eat (can be 0)

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
	while(i < ft_strlen(str))
	{
		if(!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int parse_input(char **argv, t_data *data)
{
	int i;
	long *input;

	i = 0;
	input = malloc(sizeof(long) * 5);
	if (!input)
		return (NULL);
	ft_memset(input, 0, sizeof(long) * 5);
	while(++i < 5)
	{
		if(!is_num(argv[i]))
			return (free(input), NULL);
		input[i - 1] = ft_atol(argv[i]);
	}

	if(argv[5])
		input[4] = ft_atol(argv[5]);

	if(!validate(input))
		return (free(input), NULL);

	return (input, 1);
}


