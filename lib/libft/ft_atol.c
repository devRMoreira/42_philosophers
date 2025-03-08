/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:03:35 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/08 13:59:45 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	long	sum;
	long	i;
	long	neg;

	if (!nptr)
		return (0);
	i = 0;
	neg = 1;
	sum = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] != '\0' && ft_isdigit(nptr[i]))
	{
		sum = sum * 10 + (nptr[i] - '0');
		i++;
	}
	return (sum * neg);
}
