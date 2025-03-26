/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:46:12 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/26 15:10:23 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//! input
//* 0- total philos
//* 1- time to die
//* 2- time to eat
//* 3- time to sleep
//* 4- times to eat (can be 0)

long	get_current_time()
{
	long res;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	res = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);

	return (res);
}

void	*ft_malloc(size_t total_bytes)
{
	void	*res;

	res = malloc(total_bytes);
	if(res == NULL)
		return (printf("Malloc error"), NULL);
	return res;
}

void set_int(pthread_mutex_t *mtx, int *dest, int n)
{
	pthread_mutex_lock(mtx);
	*dest = n;
	pthread_mutex_unlock(mtx);
}


int get_int(pthread_mutex_t *mtx, int *src)
{
	int res;
	pthread_mutex_lock(mtx);
	res = *src;
	pthread_mutex_unlock(mtx);
	return (res);
}

void set_long(pthread_mutex_t *mtx, long *dest, long n)
{
	pthread_mutex_lock(mtx);
	*dest = n;
	pthread_mutex_unlock(mtx);
}

void increase_long(pthread_mutex_t *mtx, long *val)
{
	pthread_mutex_lock(mtx);
	(*val)++;
	pthread_mutex_unlock(mtx);
}

long get_long(pthread_mutex_t *mtx, long *src)
{
	long res;
	pthread_mutex_lock(mtx);
	res = *src;
	pthread_mutex_unlock(mtx);
	return (res);
}

int dining_over(t_data *data)
{
	return (get_int(&data->mutex, &data->end));
}

void free_struct(t_data *data)
{
    int i;
	t_philo *philo;

	i=-1;
	while(++i < data->total_philo)
	{
		philo = data->philos + i;
		pthread_mutex_destroy(&data->forks[i].fork);
		pthread_mutex_destroy(&philo->mutex);
	}
	pthread_mutex_destroy(&data->mutex);
	free(data->forks);
	free(data->philos);
}

long	ft_usleep(long time)
{
	long	start;
	start = get_current_time();
	while ((get_current_time() - start) < time)
		usleep(time / 10);
	return(0);
}
