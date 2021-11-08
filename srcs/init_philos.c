/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:01:42 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/08 17:08:18 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int index_forks(t_table *table);

int init_philos(t_table *table)
{
	printf("init_philos\n");
	int i;

	i = table->ammount;
	table->philos = malloc(sizeof(t_philo) * i);
	if (!table->philos)
		return (0);
	i = 0;
	while (i < table->ammount)
	{
		table->philos[i].id = i + 1;
		printf("Setting id at %i\n", i + 1);
		i++;
	}
	index_forks(table);
	return (1);
}

static int index_forks(t_table *table)
{
	int i;
	int a;

	a = table->ammount;
	i = 0;
	table->philos[i].left_f = table->forks[i].forkMutex;
	table->philos[i].right_f = table->forks[a - 1].forkMutex;
	i++;
	while (i < a)
	{
		table->philos[i].left_f = table->forks[i].forkMutex;
		table->philos[i].right_f = table->forks[i - 1].forkMutex;
		i++;
	}
	return (1);
}
