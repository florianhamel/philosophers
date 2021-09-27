/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:57:00 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/27 23:38:59 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	struct timeval	now;
	long			time;

	if (gettimeofday(&now, NULL) == ERROR)
		return (ERROR);
	time = (now.tv_sec - philo->last_meal.tv_sec) * 1000;
	time += (now.tv_usec - philo->last_meal.tv_usec) / 1000;
	if (time > philo->data->param.tt_die)
		return (TRUE);
	return (FALSE);
}

long	get_ms(struct timeval ref)
{
	struct timeval	tv;
	long			ms;

	if (gettimeofday(&tv, NULL) == ERROR)
		return (ERROR);
	ms = (tv.tv_sec - ref.tv_sec) * 1000;
	ms += (tv.tv_usec - ref.tv_usec) / 1000;
	return (ms);
}
