/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:48:15 by rimagalh          #+#    #+#             */
/*   Updated: 2025/04/08 15:57:35 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_init_philos(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = -1;
	philos = data->philos;
	while (++i < data->philos_total)
	{
		philos[i].data = data;
		philos[i].id = i + 1;
		philos[i].meal_total = 0;
		philos[i].meal_timestamp = 0;
		philos[i].full = 0;
	}
}

static void	ft_init_forks(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = -1;
	philos = data->philos;
	while (++i < data->philos_total)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	philos[0].first_fork = &data->forks[0];
	if (data->philos_total == 1)
		return ;
	philos[0].second_fork = &data->forks[data->philos_total - 1];
	while (++i < data->philos_total)
	{
		if (philos[i].id % 2 == 0 && data->philos_total != 2)
		{
			philos[i].first_fork = &data->forks[i];
			philos[i].second_fork = &data->forks[i - 1];
		}
		else
		{
			philos[i].first_fork = &data->forks[i - 1];
			philos[i].second_fork = &data->forks[i];
		}
	}
}

static int	ft_init_mem(t_data *data, int philos)
{
	data->philos_threads = malloc(sizeof(pthread_t) * philos);
	if (data->philos_threads == NULL)
		return (1);
	data->philos = malloc(sizeof(t_philo) * philos);
	if (data->philos == NULL)
		return (free(data->philos_threads), 1);
	data->forks = malloc(sizeof(pthread_mutex_t) * philos);
	if (data->forks == NULL)
		return (free(data->philos), free(data->philos_threads), 1);
	return (0);
}

int	ft_init_threads(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&data->ready);
	while (++i < data->philos_total)
	{
		if (pthread_create(&data->philos_threads[i], NULL, ft_routine,
				&data->philos[i]) != 0)
			return (0);
	}
	data->time_start = ft_get_current_time();
	pthread_mutex_unlock(&data->ready);
	ft_usleep(data->time_eat - 10);
	ft_monitor_rout(data);
	i = -1;
	while (++i < data->philos_total)
	{
		if (pthread_join(data->philos_threads[i], NULL) != 0)
			return (0);
	}
	return (1);
}

int	ft_init_data(t_data *data, char **av, int ac)
{
	data->philos_total = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->meal_total = -1;
	data->philos_status = 0;
	data->philos_full = 0;
	data->time_start = 0;
	if (ac == 6)
		data->meal_total = ft_atoi(av[5]);
	if (ft_init_mem(data, data->philos_total))
		return (1);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->ready, NULL);
	ft_init_philos(data);
	ft_init_forks(data);
	return (0);
}
