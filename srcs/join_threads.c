/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:46:46 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/12 17:32:27 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->ammount)
	{
		if (pthread_join(table->philos[i].th, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
