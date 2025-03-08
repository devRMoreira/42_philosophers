/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:23:16 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/08 16:38:13 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philosopher(void *arg)
{
	return (NULL);
}

void print_error(char *descriptor)
{
	ft_printf("Error\n%s", descriptor);
}

//! delete whenever
void print_struct(t_data *data)
{
    ft_printf("Total Philosophers: %d\n", data->total_philo);
    ft_printf("Time to Die: %d\n", data->time_die);
    ft_printf("Time to Eat: %d\n", data->time_eat);
    ft_printf("Time to Sleep: %d\n", data->time_sleep);
    ft_printf("Amount to Eat: %d\n", data->amount_eat);
}

int main(int argc, char	**argv)
{
	t_data data;
	long	*input;

	if(argc >= 5 && argc <= 6)
	{
		input = parse_input(argv, &data);
		if(!input)
			return (print_error("Invalid arguments"), 1);
		print_data(&data);
		init_struct(input, &data);
	}
	else
		return (print_error("Invalid arguments"), 1);

	return (0);
}
