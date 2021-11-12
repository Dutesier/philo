/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:07:13 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/12 17:35:43 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	try_lock_fork(pthread_mutex_t *f, int *locked);

int	lock_forks(t_philo *philo)
{
	if (try_lock_fork(philo->left_f, philo->left_locked))
	{
		if (try_lock_fork(philo->right_f, philo->right_locked))
		{
			philo->state = has_fork;
			print_state(philo);
			print_state(philo);
			return (1);
		}
		set_unlocked(philo->left_f, philo->left_locked);
	}
	return (0);
}

static int	try_lock_fork(pthread_mutex_t *f, int *locked)
{
	int	status;

	status = 0;
	pthread_mutex_lock(f);
	if (*locked == 0)
	{
		*locked = 1;
		status = 1;
	}
	pthread_mutex_unlock(f);
	return (status);
}

void	set_unlocked(pthread_mutex_t *f, int *locked)
{
	pthread_mutex_lock(f);
	*locked = 0;
	pthread_mutex_unlock(f);
}
