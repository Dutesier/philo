/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:12:06 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/08 17:05:47 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

// For testing
#include <stdio.h>
// Ends here

typedef struct	s_philo
{
	pthread_t		th;

	int				id;

	pthread_mutex_t	left_f;
	pthread_mutex_t	right_f;

	int				times_e;

}				t_philo;

typedef struct	s_fork
{
	int				id;
	pthread_mutex_t forkMutex;
}				t_fork;

typedef struct	s_table
{
	int ammount;

	t_philo		*philos;
	t_fork		*forks;
	int			t_to_d;
	int			t_to_e;
	int			t_to_s;

}				t_table;



int start_threads(t_table *table);
int init_philos(t_table *table);
int init_forks(t_table *table);

void *routine(void *void_philo);
int	ft_atoi(char *str);

#endif
