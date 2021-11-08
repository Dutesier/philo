/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:15:14 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/08 17:08:04 by dareias-         ###   ########.fr       */
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
	
	if (init_philos(&table) == 0)
		return (0);

	start_threads(pointer);

	return (1);
}
