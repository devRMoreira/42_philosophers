/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:32:04 by rimagalh          #+#    #+#             */
/*   Updated: 2025/04/07 15:32:04 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int ft_monitor_status(t_philo *philo)
{
	int i;

	i = 0;
	pthread_mutex_lock(&philo->data->ready);
	if(ft_get_current_time() - philo->meal_timestamp > (size_t)philo->data->time_die)
	{
		philo->data->philos_status = 1;
	}
	else if(philo->meal_total == philo->data->meal_total &&
		philo->full == 0)
		{
			philo->data->philos_full++;
			philo->full = 1;
		}
	pthread_mutex_unlock(&philo->data->ready);
	if(philo->data->philos_full == philo->data->philos_total)
		philo->data->philos_status = 2;
	i = philo->data->philos_status;
	return (i);
}

void ft_monitor_rout(t_data *data)
{
	int	i;

	i = 0;
	while(1)
	{
		if(ft_monitor_status(&data->philos[i]))
			break;
		i++;
		if(i == data->philos_total)
			i = 0;
	}
	if(data->philos_status == 1)
		ft_print(&data->philos[i], "died.");
}
