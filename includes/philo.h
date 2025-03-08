/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:39:46 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/08 16:48:04 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_data //needs free
{
	int 			total_philo;
	int 			time_die;
	int 			time_eat;
	int 			time_sleep;
	int 			amount_eat;
	long			start_time;
	struct s_philo	*philos; //needs free (array)
	pthread_t		*threads; //needs free (array)
	pthread_mutex_t	*forks; //needs free (array)
	pthread_mutex_t	print_lock; //needs free (destroy)
}		t_data;

typedef struct s_philo //needs free
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	struct s_data 	*data;
	pthread_mutex_t	*left; //needs free (destroy)
	pthread_mutex_t	*right; //needs free (destroy)
}		t_philo;

long	*parse_input(char **argv, t_data *philo);
void	print_error(char *descriptor);
void	init_struct(long *input, t_data *data);
void	*philosopher(void *arg);
void	init_struct(long *input, t_data *data);
long	get_current_time();


#endif
