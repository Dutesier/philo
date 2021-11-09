/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:48:36 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/09 19:15:10 by dareias-         ###   ########.fr       */
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
		return (0);
	while (i < table->ammount)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		//printf("Forks[%i]: %p\n", i, (void *)(&table->forks[i]));
		i++;
	}
	if (init_locked(table) == 0)
		return (0); // We actually need to free table->forks and destroy the mutexes
	return (-42);
}
