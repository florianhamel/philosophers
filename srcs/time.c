/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:57:00 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/30 16:32:07 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(long micros)
{
	struct timeval	start;
	struct timeval	tv;
	long			time;

	gettimeofday(&start, NULL);
	time = 0;
	while (time < micros)
	{
		usleep(time / 1000);
		gettimeofday(&tv, NULL);
		time = (tv.tv_sec - start.tv_sec) * 1000000;
		time += (tv.tv_usec - start.tv_usec);
	}
	return (SUCCESS);
}

int	is_dead(t_philo *philo, struct timeval *now)
{
	long time;

	if (now->tv_sec == philo->last_meal.tv_sec && \
	now->tv_usec == philo->last_meal.tv_usec)
		return (FALSE);
	time = 0;
	time += (now->tv_sec - philo->last_meal.tv_sec) * 1000;
	time += (now->tv_usec - philo->last_meal.tv_usec) / 1000;
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
