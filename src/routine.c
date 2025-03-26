/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:05:36 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/13 12:26:07 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void start_eating(t_data *data)
{
	int i;
	if(data->total_meal == 0)
		return ;
	else if(data->total_philo == 1)
		pthread_create(&data->philos[0].thread, NULL, solo_dinner, &data->philos[0]);
	else
	{
		i = -1;
		while(++i < data->total_philo)
			pthread_create(&data->philos[i].thread, NULL, routine, &data->philos[i]);

		data->start_time = get_current_time();

		data->ready = 1;

		i = -1;
		while(++i < data->total_philo)
			pthread_join(data->philos[i].thread, NULL);
	}
	set_int(&data->mutex, &data->end, 1);
	pthread_join(data->monitor, NULL);
}

void ft_write(char status, t_philo *philo)
{
	long elapsed;


	if(philo->full)
		return ;

	pthread_mutex_lock(&philo->data->mutex);
	elapsed = get_current_time() - philo->data->start_time;

	if(status == '1')
		printf("%ld - %d has taken the first fork\n",elapsed, philo->id);
	if(status == '2')
		printf("%ld - %d has taken the second fork\n",elapsed, philo->id);
	if(status == 'e')
		printf("%ld - %d is eating\n",elapsed, philo->id);
	if(status == 's')
		printf("%ld - %d is sleeping\n",elapsed, philo->id);
	if(status == 't')
		printf("%ld - %d is thinking\n",elapsed, philo->id);
	if(status == 'd')
		printf("%ld - %d died\n",elapsed, philo->id);

	pthread_mutex_unlock(&philo->data->mutex);
}

void ft_think(t_philo *philo)
{
	ft_write('t', philo);
}


void ft_eat(t_philo *philo)
{
	printf("Philosopher %d is waiting for forks\n", philo->id);

	pthread_mutex_lock(&philo->first_fork->fork);
	ft_write('1', philo);
	pthread_mutex_lock(&philo->second_fork->fork);
	ft_write('2', philo);

	set_long(&philo->mutex, &philo->last_meal, get_current_time());

	philo->meals_eaten++;

	ft_write('e', philo);
	ft_usleep(philo->data->time_eat);
	if(philo->data->total_meal > 0 &&
		philo->meals_eaten == philo->data->total_meal)
		set_int(&philo->mutex, &philo->full, 1);

	pthread_mutex_unlock(&philo->second_fork->fork);
	pthread_mutex_unlock(&philo->first_fork->fork);
}

void *solo_dinner(void *philosopher)
{
	t_philo *philo;

	philo = (t_philo *)philosopher;

	wait_all(philo->data);
	set_long(&philo->mutex, &philo->last_meal, get_current_time());
	increase_long(&philo->data->mutex, &philo->data->threads_run);
	ft_write('1', philo);
	while(!dining_over(philo->data))
		usleep(200);
	return (NULL);
}

void *routine(void *philosopher)
{
	t_philo *philo;

	philo = (t_philo *)philosopher;

	wait_all(philo->data);

	set_long(&philo->mutex, &philo->last_meal, get_current_time());

	increase_long(&philo->data->mutex, &philo->data->threads_run);

	while(!philo->data->end)
	{
		if(philo->full)
			break;

		ft_eat(philo);

		ft_write('s', philo);
		ft_usleep(philo->data->time_sleep);

		ft_think(philo);
	}

	return NULL;
}
