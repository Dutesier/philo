/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:48:36 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/08 17:08:45 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_forks(t_table *table)
{
	int i;

	i = 0;
	table->forks = malloc(sizeof(t_fork *) * table->ammount);
	if (!table->forks)
		return (0);
	while (i <= table->ammount)
	{
		pthread_mutex_init(&table->forks[i].forkMutex, NULL);
		table->forks[i].id = i;
		i++;
	}
	return (i);
}
