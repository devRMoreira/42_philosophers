/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:23:16 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/08 14:39:43 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void print_error(char *descriptor)
{
	ft_printf("Error\n%s", descriptor);
}

//! delete whenever
void print_struct(t_data *data)
{
    printf("Total Philosophers: %d\n", data->total_philo);
    printf("Time to Die: %d\n", data->time_die);
    printf("Time to Eat: %d\n", data->time_eat);
    printf("Time to Sleep: %d\n", data->time_sleep);
    printf("Amount to Eat: %d\n", data->amount_eat);
}

int main(int argc, char	**argv)
{
	t_data philo;

	if(argc >= 5 && argc <= 6)
	{
		if(!parse_input(argv, &philo))
			return (print_error("Invalid arguments"), 1);
		print_data(&philo);
	}

	return (0);
}
