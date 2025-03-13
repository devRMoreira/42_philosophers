/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:39:46 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/13 12:24:18 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>


typedef struct s_data t_data;
typedef struct s_fork t_fork;
typedef struct s_philo t_philo;

typedef struct s_data //needs free
{
	long 			total_philo;
	long 			time_die;
	long 			time_eat;
	long 			time_sleep;
	long 			total_meal;
	long			start_time;
	int				end; //0 or 1 philo dies or all full;
	t_fork			*forks; //needs free (array)
	t_philo			*philos; //needs free (array)
	pthread_t		*threads; //needs free (array)
	pthread_mutex_t	mutex; //needs free (destroy)
}		t_data;

typedef struct s_fork
{
	int id;
	pthread_mutex_t fork;
}		t_fork;

typedef struct s_philo //needs free
{
	int				id;
	long			meals_eaten;
	long			last_meal; //time he ate last meal
	int				full; //0 or 1
	t_fork			*left_fork; //needs free (destroy)
	t_fork			*right_fork; //needs free (destroy)
	t_data 			*data; //pointer to data
	pthread_t 		thread; //each philo is a thread
}		t_philo;

long	*parse_input(char **argv, t_data *philo);
void	print_error(char *descriptor);
void	init_struct(long *input, t_data *data);
void	*philosopher(void *arg);
void	init_struct(long *input, t_data *data);
long	get_current_time();
void	*ft_malloc(size_t total_bytes);

#endif
