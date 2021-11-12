/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:48:36 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/12 16:58:53 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int table_free(t_table *table, int layer)
{
	if (layer >= 2)
	{
		free(table->philos);
		if (pthread_mutex_destroy(table->print_mutex) != 0)
			return (2);
		free(table->print_mutex);
	}
	if (layer >= 1)
	{
		if (forks_free(table, 2, table->ammount - 1))
			return (1); // Error happened while trying to free forks
	}
	return (0);
}

int forks_free(t_table *table, int layer, int sublayer)
{
	// Layer == 2 that means that everything went ok but now we need to free
	if (layer >= 2)
	{
		free(table->locked);
	}
	// Layer == 1 that means that a mutex failed to init here we take sublayer as i
	if (layer >= 1)
	{
		while (sublayer >= 0)
		{
			if (pthread_mutex_destroy(&table->forks[sublayer--]) != 0)
				return (1);
		}
		free(table->forks);
	}
	return (0);
}
