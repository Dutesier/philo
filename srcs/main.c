/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:15:14 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/08 21:02:54 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char *argv[])
{
	t_table table;
	t_table *pointer = &table;

	if (argc < 5 || argc > 6)
		return (0);
	table.ammount = ft_atoi(argv[1]);


	if (init_forks(&table) == 0)
		return (0);
	
	set_times(argv, &table.time);
	table.print_mutex = malloc(sizeof(pthread_mutex_t *));
	if (!table.print_mutex)
		return (0); // we actually need to free stuff

	if (init_philos(&table) == 0)
		return (0); // Here we actually need to free the forks
	
	start_threads(pointer);

	int i;
	i = 0;
	while (i < table.ammount)
	{
		pthread_join(table.philos[i].th, NULL);
		pthread_mutex_destroy(&table.forks[i]);
		i++;
	}
	i = 0;
	while (i < table.ammount)
	{
		pthread_mutex_destroy(&table.forks[i]);
		i++;
	}
	pthread_mutex_destroy(table.print_mutex);
	return (1);
} // MUTEXES still need destruction
