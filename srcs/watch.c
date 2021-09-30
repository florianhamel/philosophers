/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:03:24 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/30 16:25:33 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	watch_death(t_philo *philo_lst)
{
	t_philo			*current;
	struct timeval	now;

	current = philo_lst;
	while (current)
	{
		if (pthread_mutex_lock(&current->death) == ERROR)
			return (ERROR);
		if (gettimeofday(&now, NULL) == ERROR)
		{
			free_philo_fork(philo_lst);
			return (ERROR);
		}
		if (is_dead(current, &now))
		{
			simulate_action(current, DIE, NO_ARG);
			free_philo_fork(philo_lst);
			return (TRUE);
		}
		if (pthread_mutex_unlock(&current->death) == ERROR)
			return (ERROR);
		current = current->next;
	}
	return (FALSE);
}

int	watch_meal(t_philo *philo_lst)
{
	t_philo	*current;

	if (philo_lst->data->param.max_meals == NO_ARG)
		return (NO_ARG);
	current = philo_lst;
	while (current)
	{
		if (current->nb_meals < current->data->param.max_meals)
			return (FALSE);
		current = current->next;
	}
	free_philo_fork(philo_lst);
	return (TRUE);
}
