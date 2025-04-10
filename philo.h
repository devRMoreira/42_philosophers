/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:48:12 by rimagalh          #+#    #+#             */
/*   Updated: 2025/04/08 16:03:52 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo
{
	int				id;
	int				full;
	int				meal_total;
	size_t			meal_timestamp;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				time_eat;
	int				time_die;
	int				time_sleep;
	int				meal_total;
	int				philos_full;
	int				philos_status;
	int				philos_total;
	size_t			time_start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	ready;
	pthread_t		*philos_threads;
	t_philo			*philos;
}	t_data;

int		ft_atoi(const char *str);
int		ft_init_threads(t_data *data);
void	ft_free(t_data *data);
size_t	ft_get_current_time(void);
int		ft_init_data(t_data *data, char **argv, int argc);
int		ft_isnumber(char *str);
void	*ft_routine(void *philosopher);
void	ft_monitor_rout(t_data *data);
void	ft_print(t_philo *philo, char *str);
void	ft_usleep(size_t time_sleep);
int		ft_valid_input(int ac, char **av);

#endif
