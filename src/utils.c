/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:46:12 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/08 16:49:22 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//! input
//* 0- total philos
//* 1- time to die
//* 2- time to eat
//* 3- time to sleep
//* 4- times to eat (can be 0)

//* typedef struct s_data
//
// 	int 			total_philo;
// 	int 			time_die;
// 	int 			time_eat;
// 	int 			time_sleep;
// 	int 			amount_eat;
// 	long			start_time;
// 	t_philo			*philos;
// 	pthread_t		*threads;
// 	pthread_mutex_t	*forks;
// 	pthread_mutex_t	print_lock;
//* t_data;

//* typedef struct s_philo
//
// 	int				id;
// 	int				meals_eaten;
// 	long			last_meal;
// 	struct s_data 	*data;
// 	pthread_mutex_t	*left;
// 	pthread_mutex_t	*right;
//* t_philo;

long	get_current_time()
{
	long res;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	res = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);

	return (res);
}

static t_philo	new_philo(int id, t_data *data)
{
	t_philo philo;

	philo.id = id;
	philo.meals_eaten = -1;
	philo.last_meal = -1;
	philo.left = &data->forks[id];
	philo.right = &data->forks[(id + 1) % data->total_philo];
	philo.data = data;
	return (philo);
}


static void	mutex_thread_init(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->total_philo)
		pthread_mutex_init(&data->forks[i], NULL);
	pthread_mutex_init(&data->print_lock, NULL);
	i = -1;
	while (++i < data->total_philo)
	{
		data->philos[i] = new_philo(i, data);
		pthread_create(&data->threads[i], NULL, philosopher, &data->philos[i]);
	}
}

void	init_struct(long *input, t_data *data)
{
	data->total_philo = input[0];
	data->time_die = input[1];
	data->time_eat = input[2];
	data->time_sleep = input[3];
	data->amount_eat = input[4];
	data->start_time = get_current_time();
	data->threads = malloc(sizeof(pthread_t) * data->total_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->total_philo);
	mutex_thread_init(data);
}
