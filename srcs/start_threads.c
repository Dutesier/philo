/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:43:35 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/08 16:48:14 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int start_threads(t_table *table)
{
	printf("Entered s_threads\n");
	printf("table: %p\n", table);
	int i;

	i = table->ammount;
	printf("table->ammount:  %i\n", i);
	
	i = 0;
	while (i < table->ammount)
	{
		printf("Trying to create thread for philo %i, with id %i\n", i, table->philos[i].id);
		if (pthread_create(&table->philos[i].th, NULL, &routine, (void *)(&table->philos[i])))
			return (i);
		i++;
	}
	printf("Left s_threads\n");
	return (i);
}
