/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:32:23 by rimagalh          #+#    #+#             */
/*   Updated: 2025/04/07 15:32:23 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	ft_print(philo, "has taken the first fork.");
	pthread_mutex_lock(philo->second_fork);
	ft_print(philo, "has taken the second fork.");
	philo->meal_timestamp = ft_get_current_time();
	ft_print(philo, "is eating.");
	ft_usleep(philo->data->time_eat);
	if(philo->meal_total < philo->data->meal_total)
	philo->meal_total++;
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
	return ;
}

void *ft_routine (void *philosopher)
{
	t_philo *philo;
	philo = (t_philo *)philosopher;
	pthread_mutex_lock(&philo->data->ready);
	pthread_mutex_unlock(&philo->data->ready);
	philo->meal_timestamp = philo->data->time_start;
	if(philo->data->philos_total == 1)
	{
		ft_print(philo, "has taken a fork.");
		ft_usleep(philo->data->time_die);
		return (NULL);
	}
	if(philo->id % 2 != 0)
	{
		ft_print(philo, "is thinking.");
		ft_usleep(philo->data->time_eat);
	}
	while(philo->data->philos_status == 0)
	{
		ft_eat(philo);
		ft_print(philo, "is sleeping.");
		ft_usleep(philo->data->time_sleep);
		ft_print(philo, "is thinking.");
	}

	return (NULL);
}
