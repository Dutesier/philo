/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:48:36 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/15 10:17:40 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	table_free(t_table *table, int layer)
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
			return (1);
	}
	return (0);
}

int	forks_free(t_table *table, int layer, int sublayer)
{
	if (layer >= 2)
	{
		free(table->locked);
	}
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
