/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:20:24 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/08 16:24:19 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *void_philo)
{
	printf("Entered routine\n");
	t_philo *philo;

	philo  = (t_philo *)void_philo;
	printf("My id: %i\n", philo->id);
	printf("Left routine\n");
	return (NULL);
}
