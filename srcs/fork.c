/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:52:31 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/27 20:34:10 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	unlock_first_fork(t_philo *philo)
{
	int	left;
	int	right;

	right = philo->id - 1;
	if (right == 0)
		left = philo->data->param.nb_philos - 1;
	else
		left = right - 1;
	if (ft_iseven(philo->id))
	{
		if (pthread_mutex_unlock(&philo->data->fork[left]) == ERROR)
			return (ERROR);
	}
	else if (pthread_mutex_unlock(&philo->data->fork[right]) == ERROR)
			return (ERROR);
	return (SUCCESS);
}

int	unlock_second_fork(t_philo *philo)
{
	int	left;
	int	right;

	right = philo->id - 1;
	if (right == 0)
		left = philo->data->param.nb_philos - 1;
	else
		left = right - 1;
	if (ft_iseven(philo->id))
	{
		if (pthread_mutex_unlock(&philo->data->fork[right]) == ERROR)
			return (ERROR);
	}
	else if (pthread_mutex_unlock(&philo->data->fork[left]) == ERROR)
			return (ERROR);
	return (SUCCESS);
}

int	lock_first_fork(t_philo *philo)
{
	int	left;
	int	right;

	right = philo->id - 1;
	if (right == 0)
		left = philo->data->param.nb_philos - 1;
	else
		left = right - 1;
	if (ft_iseven(philo->id))
	{
		if (pthread_mutex_lock(&philo->data->fork[left]) == ERROR)
			return (ERROR);
	}
	else if (pthread_mutex_lock(&philo->data->fork[right]) == ERROR)
			return (ERROR);
	return (SUCCESS);
}

int	lock_second_fork(t_philo *philo)
{
	int	left;
	int	right;

	right = philo->id - 1;
	if (right == 0)
		left = philo->data->param.nb_philos - 1;
	else
		left = right - 1;
	if (ft_iseven(philo->id))
	{
		if (pthread_mutex_lock(&philo->data->fork[right]) == ERROR)
			return (ERROR);
	}
	else if (pthread_mutex_lock(&philo->data->fork[left]) == ERROR)
			return (ERROR);
	return (SUCCESS);
}
