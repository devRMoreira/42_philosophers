/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:39:46 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/08 14:39:00 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include "../lib/libft/libft.h"

typedef struct s_data
{
	int total_philo;
	int time_die;
	int time_eat;
	int time_sleep;
	int amount_eat;
}		t_data;

int		parse_input(char **argv, t_data *philo);
void	print_error(char *descriptor);

#endif
