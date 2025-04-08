/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:32:34 by rimagalh          #+#    #+#             */
/*   Updated: 2025/04/07 15:32:34 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = -1;
	neg = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[++i] == '-')
		neg *= -1;
	if (str[i] == '+' && str[i - 1] != '+' && str[i - 1] != '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += (str[i] - 48);
		i++;
	}
	return (res * neg);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

void	ft_free(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philos_total)
	{
		pthread_mutex_destroy(&data->forks[i]);
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->ready);
	free(data->philos);
	free(data->forks);
	free(data->philos_threads);
}

size_t	ft_get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(size_t time_sleep)
{
	size_t	start;

	start = 0;
	start = ft_get_current_time();
	while ((ft_get_current_time() - start) < time_sleep)
		usleep(100);
}
