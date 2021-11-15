/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:43:35 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/15 09:33:30 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_threads(t_table *table)
{
	int	i;

	i = table->ammount;
	i = 0;
	while (i < table->ammount)
	{
		
		if (pthread_create(&table->philos[i].th,
				NULL, &routine, (void *)(&table->philos[i])))
			return (i);
		i++;
	}
	return (i);
}
