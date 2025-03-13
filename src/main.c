/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:23:16 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/13 11:17:57 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philosopher(void *arg)
{
	return (NULL);
}

void print_error(char *descriptor)
{
	printf("Error\n%s", descriptor);
}

int main(int argc, char	**argv)
{
	t_data data;
	long	*input;

	if(argc == 5 || argc == 6)
	{
		input = parse_input(argv, &data);
		if(!input)
			return (print_error("Invalid arguments"), 1);
		init_struct(input, &data);

		philosopher(&data);

		free_struct(&data);
	}
	else
		return (print_error("Invalid arguments"), 1);

	return (0);
}
