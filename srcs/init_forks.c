/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:48:36 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/12 16:46:34 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int init_locked(t_table *table)
{
	int i;

	i = 0;
	table->locked = malloc(sizeof(int) * table->ammount);
	if (!table->locked)
		return (0);
	if (table->ammount == 1)
	{
		table->locked[0] = 1;
		return (1);
	}
	while (i < table->ammount)
	{
		table->locked[i] = 0;
		i++;
	}
	return (i);
}

int init_forks(t_table *table)
{
	int i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->ammount);
	if (!table->forks)
		return (1);
	while (i < table->ammount)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (1 + forks_free(table, 1, i - 1));
		i++;
	}
	if (init_locked(table) == 0)
		return (1 + forks_free(table, 1, i - 1)); // We actually need to free table->forks and destroy the mutexes
	return(0);
}
