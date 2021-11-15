/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:20:24 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/15 13:08:55 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eat(t_philo *philo);
static int	go_sleep(t_philo *philo);
static int	think(t_philo *philo);
static int	ft_full(t_philo *philo);

//static void print_test(t_philo *philo);

void	*routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	philo->state = thinking;
	while (philo->state != dead && ft_full(philo))
	{
		if (philo->state == thinking && lock_forks(philo))
			eat(philo);
	//	print_test(philo);
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
	philo->times_eaten++;
	gettimeofday(&philo->last_meal, NULL);
	print_state(philo);
	//print_test(philo);
	ft_sleep(philo->last_meal, philo->time.t_to_e);
	//usleep(philo->time.t_to_e * 1000);
	//print_test(philo);
	return (1);
}

static int	go_sleep(t_philo *philo)
{
	long long int	s;

	philo->state = sleeping;
	print_state(philo);
	set_unlocked(philo->left_f, philo->left_locked);
	set_unlocked(philo->right_f, philo->right_locked);
	s = starvation(philo);
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

/*tatic void print_test(t_philo *philo)
{
	pthread_mutex_lock(philo->print_mutex);
	long long int t;

	t = get_timeval(philo->time.t_start);
	printf("%lld %i\n", t / 1000, philo->id);
	pthread_mutex_unlock(philo->print_mutex);
}*/

static int	ft_full(t_philo *philo)
{
	if (*philo->all_full == 0 || *philo->all_full == -2)
		return (0);
	return (1);
}
