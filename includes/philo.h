/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:39:46 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/26 15:11:46 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
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
	long			threads_run;
	int				ready;
	int				end; //0 or 1 philo dies or all full;
	t_fork			*forks; //needs free (array)
	t_philo			*philos; //needs free (array)
	pthread_t		*threads; //needs free (array)
	pthread_t		monitor; //needs free
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
	t_fork			*first_fork; //needs free (destroy)
	t_fork			*second_fork; //needs free (destroy)
	t_data 			*data; //pointer to data
	pthread_mutex_t mutex;
	pthread_t 		thread; //each philo is a thread
}		t_philo;

long	*parse_input(char **argv, int argc);
void	print_error(char *descriptor);
void	init_struct(long *input, t_data *data);
void	mutex_thread_init(t_data *data);
void	print_error(char *descriptor);
void	*ft_malloc(size_t total_bytes);
void	set_int(pthread_mutex_t *mtx, int *dest, int n);
int		get_int(pthread_mutex_t *mtx, int *src);
void	set_long(pthread_mutex_t *mtx, long *dest, long n);
long	get_long(pthread_mutex_t *mtx, long *src);
int		dining_over(t_data *data);
long	ft_usleep(long time);
void	wait_all(t_data *data);
void	start_eating(t_data *data);
void	ft_write(char status, t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_eat(t_philo *philo);
void	*routine(void *philosopher);
void	free_struct(t_data *data);
long	get_current_time();
void	*ft_monitor(void *input);
void	*ft_malloc(size_t total_bytes);
int wait_all_threads(t_data *data);
void *solo_dinner(void *philosopher);
void increase_long(pthread_mutex_t *mtx, long *val);

#endif
