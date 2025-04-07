/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:48:18 by rimagalh          #+#    #+#             */
/*   Updated: 2025/04/07 16:56:30 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void 	ft_print(t_philo *philo, char *str)
{
	size_t time;

	time = ft_get_current_time() - philo->data->time_start;
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %i %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
}

int main(int ac, char **av)
{
	int		res;
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		res = ft_valid_input(ac, av);
		if(!res)
			return printf("Invalid arguments."), 1;
		if(ft_init_data(&data, av, ac))
			return printf("Data init error."), 1;
		if(!ft_init_threads(&data))
			return (ft_free(&data), printf("Thread init error."));
		ft_free(&data);
	}
	else
	{
		printf("Invalid arguments.");
	}
}
