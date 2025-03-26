/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:16:04 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/26 14:50:57 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int philo_died(t_philo *philo)
{
	long elapsed;
	long ttd;

	if(get_int(&philo->mutex, &philo->full))
		return 0;

	elapsed = get_current_time() - get_long(&philo->mutex, &philo->last_meal);
	ttd = philo->data->time_die;
	if(elapsed > ttd)
		return 1;
	else
		return 0;
}

void *ft_monitor(void *input)
{
	t_data *data = input;
	int i;

	while(!wait_all_threads(data));

	while(!dining_over(data))
	{
		i = -1;
		while(++i < data->total_philo && dining_over(data))
		{
			if(philo_died(&data->philos[i]))
			{
				set_int(&data->mutex, &data->end, 1);
				ft_write('d', &data->philos[i]);
			}
		}
	}
	return (NULL);
}




int wait_all_threads(t_data *data)
{
	int  res;

	res = 0;
	pthread_mutex_lock(&data->mutex);
	if(data->threads_run == data->total_philo)
		res = 1;
	pthread_mutex_unlock(&data->mutex);
	return (res);
}


