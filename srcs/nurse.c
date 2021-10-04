/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nurse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:03:24 by fhamel            #+#    #+#             */
/*   Updated: 2021/10/04 15:18:58 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo_lst)
{
	int				ret;
	t_philo			*current;
	struct timeval	now;

	current = philo_lst;
	while (current)
	{
		if (pthread_mutex_lock(&current->time) == ERROR)
			return (ERROR);
		if (gettimeofday(&now, NULL) == ERROR)
			return (ERROR);
		ret = is_dead(current, &now);
		if (pthread_mutex_unlock(&current->time) == ERROR)
			return (ERROR);
		if (ret == TRUE)
		{
			pthread_mutex_lock(&philo_lst->data->write);
			philo_lst->data->sb_died = TRUE;
			do_die(current);
			pthread_mutex_unlock(&philo_lst->data->write);
			return (TRUE);
		}
		current = current->next;
	}
	return (FALSE);
}

int	check_meal(t_philo *philo_lst)
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
	return (TRUE);
}
