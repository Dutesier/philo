/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:20:24 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/09 19:16:40 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int eat(t_philo *philo);
static int go_sleep(t_philo *philo);
static int think(t_philo *philo);

void *routine(void *void_philo)
{
	t_philo *philo;

	philo  = (t_philo *)void_philo;
	
	//printf("My id: %i\nMy t_start: %ld\n", philo->id, philo->time.t_start.tv_sec * 1000 + philo->time.t_start.tv_usec);
	philo->state = thinking;
	while (philo->state != dead)
	{
		if (philo->state == thinking && lock_forks(philo))
			eat(philo);
		if (philo->state == eating)
			go_sleep(philo);
		if (starvation(philo) < 0)
		{
			philo->state = dead;
			print_state(philo);
		}
		if (philo->state == sleeping)
			think(philo);
	}
	//printf("Left routine\n");
	return (NULL);
}

static int eat(t_philo *philo)
{

	//printf("Fork Left Philo[%i]: %p\n", philo->id, (void *)philo->left_f);
	//printf("Fork Right Philo[%i]: %p\n", philo->id, (void *)philo->right_f);

	//printf("My print_mutex %p\n", philo->print_mutex);
		
	philo->state = eating;
	print_state(philo);
	gettimeofday(&philo->last_meal, NULL);
	usleep(philo->time.t_to_e * 1000);
	philo->times_eaten++;
	
	return (1);
}

static int go_sleep(t_philo *philo)
{
	set_unlocked(philo->left_f, philo->left_locked);
	set_unlocked(philo->right_f, philo->right_locked);
	long long int s;

	s = starvation(philo);
	philo->state = sleeping;
	print_state(philo);
	if (s / 1000 <= philo->time.t_to_s)
	{
		if (s < 0)
			s = 0;
		//printf("%i Gonna die during sleep\n", philo->id);
		usleep(s);
		philo->state = dead;
		print_state(philo);
		return (0);
	}
	usleep(philo->time.t_to_s * 1000);
	return (1);
}

static int think(t_philo *philo)
{
	philo->state = thinking;
	print_state(philo);
	usleep(100); //Just a small buffer
	return (1);
}
