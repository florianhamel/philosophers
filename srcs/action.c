/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:32:31 by fhamel            #+#    #+#             */
/*   Updated: 2021/10/04 16:04:13 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulate_action(t_philo *philo, int flag, long time)
{
	long	ms;

	ms = get_ms(philo->data->start);
	if (pthread_mutex_lock(&philo->data->write) == ERROR)
		return (ERROR);
	if (!philo->data->sb_died && flag == FORK)
		printf("%lums: Philo %d has taken a fork\n", ms, philo->id);
	else if (!philo->data->sb_died && flag == EAT)
		printf("%lums: Philo %d is eating\n", ms, philo->id);
	else if (!philo->data->sb_died && flag == SLEEP)
		printf("%lums: Philo %d is sleeping\n", ms, philo->id);
	else if (!philo->data->sb_died && flag == THINK)
		printf("%lums: Philo %d is thinking\n", ms, philo->id);
	if (pthread_mutex_unlock(&philo->data->write) == ERROR)
		return (ERROR);
	if (!philo->data->sb_died && time != NO_ARG && \
	ft_usleep(time * 1000) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

void	do_die(t_philo *philo)
{
	long	ms;

	ms = get_ms(philo->data->start);
	printf("%lums: Philo %d died\n", ms, philo->id);
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
	if (pthread_mutex_lock(&philo->time) == ERROR)
		return (ERROR);
	if (gettimeofday(&philo->last_meal, NULL) == ERROR)
		return (ERROR);
	philo->nb_meals++;
	if (pthread_mutex_unlock(&philo->time) == ERROR)
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
	if (simulate_action(philo, THINK, 2) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
