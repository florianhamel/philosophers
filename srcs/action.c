/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:32:31 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/30 16:19:50 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulate_action(t_philo *philo, int flag, long time)
{
	long	ms;

	ms = get_ms(philo->data->start);
	if (pthread_mutex_lock(&philo->data->write) == ERROR)
		return (ERROR);
	if (flag == FORK)
		printf("%lums: Philo %d has taken a fork\n", ms, philo->id);
	else if (flag == EAT)
		printf("%lums: Philo %d is eating\n", ms, philo->id);
	else if (flag == SLEEP)
		printf("%lums: Philo %d is sleeping\n", ms, philo->id);
	else if (flag == THINK)
		printf("%lums: Philo %d is thinking\n", ms, philo->id);
	else if (flag == DIE)
		printf("%lums: Philo %d died\n", ms, philo->id);
	if (pthread_mutex_unlock(&philo->data->write) == ERROR)
		return (ERROR);
	if (time != NO_ARG && ft_usleep(time * 1000) == ERROR)
			return (ERROR);
	return (SUCCESS);
}

int	do_eat(t_philo *philo)
{
	if (lock_first_fork(philo) == ERROR)
		return (ERROR);
	if (simulate_action(philo, FORK, NO_ARG) == ERROR)
		return (ERROR);
	if (lock_second_fork(philo) == ERROR)
		return (ERROR);
	if (simulate_action(philo, FORK, NO_ARG) == ERROR)
		return (ERROR);
	if (pthread_mutex_lock(&philo->death) == ERROR)
		return (ERROR);
	if (gettimeofday(&philo->last_meal, NULL) == ERROR)
		return (ERROR);
	philo->nb_meals++;
	if (pthread_mutex_unlock(&philo->death) == ERROR)
		return (ERROR);
	if (simulate_action(philo, EAT, philo->data->param.tt_eat) == ERROR)
		return (ERROR);
	if (unlock_first_fork(philo) == ERROR)
		return (ERROR);
	if (unlock_second_fork(philo) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	do_sleep(t_philo *philo)
{
	if (simulate_action(philo, SLEEP, philo->data->param.tt_sleep) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	do_think(t_philo *philo)
{
	if (simulate_action(philo, THINK, 5) == ERROR)
		return (ERROR);
	return (SUCCESS);
}