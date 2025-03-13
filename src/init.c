/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:29:18 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/13 12:24:18 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_philo	new_philo(int id, t_data *data)
{
	t_philo philo;

	philo.id = id;
	philo.meals_eaten = 0;
	philo.last_meal = -1;
	philo.full = 0;
	philo.left_fork = &data->forks[id];
	philo.right_fork = &data->forks[(id + 1) % data->total_philo];
	if(id % 2 == 0)
	{
		philo.right_fork = &data->forks[id];
		philo.left_fork = &data->forks[(id + 1) % data->total_philo];
	}
	philo.data = data;
	return (philo);
}


static void	mutex_thread_init(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->total_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		data->forks[i].id = i;
	}
	pthread_mutex_init(&data->mutex, NULL);
	i = -1;
	while (++i < data->total_philo)
		data->philos[i] = new_philo(i, data);
}

void	init_struct(long *input, t_data *data)
{
	data->total_philo = input[0];
	data->time_die = input[1] * 1000;
	data->time_eat = input[2] * 1000;
	data->time_sleep = input[3] * 1000;
	if(input[4])
		data->total_meal = input[4] * 1000;
	else
		data->total_meal = -1;
	data->end = 0;
	data->start_time = get_current_time();
	data->philos = ft_malloc(sizeof(t_philo) * data->total_philo);
	data->forks = ft_malloc(sizeof(pthread_mutex_t) * data->total_philo);
	mutex_thread_init(data);
}
