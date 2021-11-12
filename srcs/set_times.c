/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_times.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:48:35 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/12 17:32:11 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_times(char *argv[], t_times *time)
{
	gettimeofday(&time->t_start, NULL);
	time->t_to_d = ft_atoi(argv[2]);
	time->t_to_e = ft_atoi(argv[3]);
	time->t_to_s = ft_atoi(argv[4]);
	if (argv[5])
		time->full = ft_atoi(argv[5]);
	else
		time->full = -1;
}
