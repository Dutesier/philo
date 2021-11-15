/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:12:06 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/15 13:03:54 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>

typedef enum e_state
{
	has_fork,
	eating,
	sleeping,
	thinking,
	dead
}			t_state;

typedef struct timeval	t_timeval;

typedef struct s_times
{
	t_timeval	t_start;
	int			t_to_d;
	int			t_to_e;
	int			t_to_s;
	int			full;
}				t_times;

typedef struct s_philo
{
	pthread_t		th;

	int				id;
	t_state			state;

	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	*print_mutex;

	int				*left_locked;
	int				*right_locked;

	int				times_eaten;
	t_timeval		last_meal;

	int				*killer;
	int				*all_full;

	t_times			time;

}				t_philo;

typedef struct s_table
{
	int					ammount;
	int					*killer;
	int					*all_full;

	t_philo				*philos;

	pthread_mutex_t		*forks;
	int					*locked;

	t_times				time;

	pthread_mutex_t		*print_mutex;

}				t_table;

int				start_threads(t_table *table);
int				join_threads(t_table *table);
int				init_philos(t_table *table);
int				init_forks(t_table *table);

void			*routine(void *void_philo);
int				ft_atoi(char *str);
void			set_times(char *argv[], t_times *time, int ac);

void			print_state(t_philo *philo);
long long int	get_timeval(t_timeval t_start);
long long int	starvation(t_philo *philo);
int				lock_forks(t_philo *philo);
void			set_unlocked(pthread_mutex_t *f, int *locked);

int				table_free(t_table *table, int layer);
int				forks_free(t_table *table, int layer, int sublayer);

void			ft_sleep(t_timeval t, long long s);

#endif
