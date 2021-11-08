/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:08:18 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/29 18:24:53 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int					negative;
	unsigned long int	atoix;

	negative = 1;
	atoix = 0;
	while ((8 < *str && *str < 14) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9' && *str)
	{
		atoix = atoix * 10 + ((int)*str - 48);
		str++;
	}
	if (atoix > 9223372036854775807 && negative == 1)
		return (-1);
	else if (atoix > 9223372036854775808U && negative == -1)
		return (0);
	else
		return (atoix * negative);
}
