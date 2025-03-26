/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:29:18 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/26 14:28:43 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_philo	new_philo(int id, t_data *data)
{
	t_philo philo;

	philo.id = id + 1;
	philo.meals_eaten = 0;
	philo.last_meal = -1;
	philo.full = 0;
	philo.first_fork = &data->forks[id];
	philo.second_fork = &data->forks[(id + 1) % data->total_philo];
	pthread_mutex_init(&philo.mutex, NULL);
	if(id % 2 == 0)
	{
		philo.first_fork = &data->forks[(id + 1) % data->total_philo];
		philo.second_fork = &data->forks[id];
	}
	philo.data = data;
	return (philo);
}

void mutex_thread_init(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->total_philo)
	{
		pthread_mutex_init(&data->forks[i].fork, NULL);
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
	data->threads_run = 0;
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
	data->forks = ft_malloc(sizeof(t_fork) * data->total_philo);
	mutex_thread_init(data);
}
