/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starvation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:48:19 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/09 19:07:45 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int starvation(t_philo *philo) 
{
	long long int t;

	t = get_timeval(philo->last_meal); //time elapsed since last meal in microseconds
	t = philo->time.t_to_d * 1000 - t; // How long I have before I die if i dont eat
	return (t); //in microseconds
}
