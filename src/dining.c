/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
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
	if(data->total_philo == 1)
		return ;

	i = -1;
	while(++i < data->total_philo)
		pthread_create(&data->philos[i].thread, NULL, dining, &data->philos[i]);

}



void *dining(void *philosopher)
{
	t_philo *philo;

	philo = (t_philo *)philosopher;

	wait_all(philo->data); //! need to wait for all philos to init to start at the same time

	return NULL;
}
