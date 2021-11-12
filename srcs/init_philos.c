/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:01:42 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/12 14:34:15 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int index_forks(t_table *table);
static int load_times(t_table *table);
static int set_locked(t_table *table);

int init_philos(t_table *table)
{
	int i;

	i = table->ammount;
	table->philos = malloc(sizeof(t_philo) * i);
	if (!table->philos)
		return (0);
	i = 0;
	while (i < table->ammount)
	{
		table->philos[i].id = i + 1;
		table->philos[i].print_mutex = table->print_mutex;
		gettimeofday(&table->philos[i].last_meal, NULL);
		table->philos[i].killer = table->killer;
		//printf("Setting id at %i\n", i + 1);
		i++;
	}
	index_forks(table);
	set_locked(table);
	load_times(table);
	return (1);
}

static int index_forks(t_table *table)
{
	int i;
	int a;

	a = table->ammount;
	i = 0;
	table->philos[i].left_f = &table->forks[i];
	table->philos[i].right_f = &table->forks[a - 1];
	i++;
	while (i < a)
	{
		table->philos[i].left_f = &table->forks[i];
		table->philos[i].right_f = &table->forks[i - 1];
		i++;
	}
	return (1);
}

static int load_times(t_table *table)
{
	int i;
	int a;

	a = table->ammount;
	i = 0;
	while (i < a)
	{
		table->philos[i].time = table->time;
		i++;
	}
	return (i);
}

static int set_locked(t_table *table)
{
	int i;
	int a;

	i = 0;
	a = table->ammount;
	table->philos[i].left_locked = &table->locked[i];
	table->philos[i].right_locked = &table->locked[a - 1];
	i++;
	while (i < a)
	{
		table->philos[i].left_locked = &table->locked[i];
		table->philos[i].right_locked = &table->locked[i - 1];
		i++;
	}
	return (1);
}
