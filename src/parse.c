/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:50:13 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/08 14:37:22 by rimagalh         ###   ########.fr       */
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
static void init_struct(long *input, t_data *philo)
{
	philo->total_philo = input[0];
	philo->time_die = input[1];
	philo->time_eat = input[2];
	philo->time_sleep = input[3];
	philo->amount_eat = input[4];
}

int parse_input(char **argv, t_data *philo)
{
	int i;
	long *input;

	i = 0;
	input = malloc(sizeof(long) * 5);
	if (!input)
		return (1);
	ft_memset(input, 0, sizeof(long *) * 5);
	while(++i < 5)
		input[i - 1] = ft_atol(argv[i]);

	if(argv[5])
		input[4] = ft_atol(argv[5]);

	if(!validate(input))
		return (free(input), 0);

	init_struct(input, philo);
	return (1);
}


