/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:30:33 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/18 10:29:08 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	get_timeval(struct timeval t_start);

static void	update_killers(t_philo *philo)
{
	if (philo->times_eaten == philo->time.full && philo->state == eating
		&& *philo->all_full > 0)
		*philo->all_full = *philo->all_full - 1;
	if (philo->state == dead && *philo->killer == 0)
		*philo->killer = 1;
}

void	print_state(t_philo *philo)
{
	long long int	t;
	char			*state[5];

	pthread_mutex_lock(philo->print_mutex);
	state[0] = "has taken a fork";
	state[1] = "is eating";
	state[2] = "is sleeping";
	state[3] = "is thinking";
	state[4] = "died";
	t = get_timeval(philo->time.t_start);
	update_killers(philo);
	if (*philo->killer != 2 && *philo->all_full != -2)
	{	
		printf("%lld %i %s\n", t / 1000, philo->id, state[philo->state]);
		if (*philo->killer == 1)
			*philo->killer = 2;
		if (*philo->all_full == 0)
			*philo->all_full = -2;
	}
	if (*philo->killer == 2)
		philo->state = dead;
	pthread_mutex_unlock(philo->print_mutex);
}

long long int	get_timeval(struct timeval t_start)
{
	long long int	t;
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	t = (curr.tv_sec - t_start.tv_sec) * 1000000
		+ curr.tv_usec - t_start.tv_usec;
	return (t);
}
