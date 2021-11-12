/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:15:14 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/12 16:57:12 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char *argv[])
{
	t_table table;
	int	stat;

	stat = 0;
	table.killer = &stat;
	if (argc < 5 || argc > 6)
		return (0);
	table.ammount = ft_atoi(argv[1]);
	if (table.ammount <= 0)
		return (0);
	if (init_forks(&table))
		return (0);
	set_times(argv, &table.time);
	table.print_mutex = malloc(sizeof(pthread_mutex_t *));
	if (!table.print_mutex)
		return (table_free(&table, 1));
	if (init_philos(&table) == 0)
		return (table_free(&table, 2));
	start_threads(&table);
	join_threads(&table);
	return (table_free(&table, 2));
} 
