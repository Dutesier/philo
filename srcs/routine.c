/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:20:24 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/12 17:38:20 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eat(t_philo *philo);
static int	go_sleep(t_philo *philo);
static int	think(t_philo *philo);

void	*routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	philo->state = thinking;
	while (philo->state != dead && philo->time.full != philo->times_eaten)
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
	return (NULL);
}

static int	eat(t_philo *philo)
{	
	philo->state = eating;
	print_state(philo);
	gettimeofday(&philo->last_meal, NULL);
	usleep(philo->time.t_to_e * 1000);
	philo->times_eaten++;
	return (1);
}

static int	go_sleep(t_philo *philo)
{
	long long int	s;

	s = starvation(philo);
	philo->state = sleeping;
	print_state(philo);
	set_unlocked(philo->left_f, philo->left_locked);
	set_unlocked(philo->right_f, philo->right_locked);
	if (s / 1000 <= philo->time.t_to_s)
	{
		if (s < 0)
			s = 0;
		usleep(s);
		philo->state = dead;
		print_state(philo);
		return (0);
	}
	usleep(philo->time.t_to_s * 1000);
	return (1);
}

static int	think(t_philo *philo)
{
	philo->state = thinking;
	print_state(philo);
	usleep(10);
	return (1);
}
