/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:51:21 by dareias-          #+#    #+#             */
/*   Updated: 2021/11/15 14:41:42 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
 * Usleep is adding 4 miliseconds so we circumvent this by using msessa approach
 * t = Beggining of sleep in microseconds
 * s = intended duration of sleep in miliseconds
 * 1000 microseconds =  1 milisecond
 * usleep sleeps for x microseconds
 * get_timeval returns microseconds
*/

void	ft_sleep(t_timeval t, long long s)
{
	usleep((s - (s / 10)) * 1000);
	while (get_timeval(t) <= s * 1000)
		continue ;
}
