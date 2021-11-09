/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:30:33 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/09 17:52:07 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int get_timeval(t_timeval t_start);
void print_state(t_philo *philo)
{
	pthread_mutex_lock(philo->print_mutex);
	//t_timeval test;
	//gettimeofday(&test, NULL);
	//printf("Time: %li sec and %i microsec\n", test.tv_sec, test.tv_usec);
	long long int t;
	char *state[5];

	state[0] = "has taken a fork";
	state[1] = "is eating";
	state[2] = "is sleeping";
	state[3] = "is thinking";
	state[4] = "has died";
	t = get_timeval(philo->time.t_start);
	printf("%lld %i %s\n", t / 1000, philo->id, state[philo->state]);
	pthread_mutex_unlock(philo->print_mutex);
}

long long int get_timeval(t_timeval t_start)
{
	long long int t;
	t_timeval curr;

	gettimeofday(&curr, NULL);
	t = (curr.tv_sec - t_start.tv_sec) * 1000000 + curr.tv_usec - t_start.tv_usec;
	return (t); // in microseconds
}
