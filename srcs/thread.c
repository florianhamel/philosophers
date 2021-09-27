/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:19:00 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/27 20:38:50 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_philo(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	while (TRUE)
	{
		if (do_eat(philo) == ERROR)
			return (NULL);
		if (do_sleep(philo) == ERROR)
			return (NULL);
		if (do_think(philo) == ERROR)
			return (NULL);
	}
	return (NULL);
}

void	*start_watch(void *void_lst)
{
	t_philo *current;

	current = (t_philo *)void_lst;
	while (TRUE)
	{}
	return (NULL);
}

t_philo	*create_philos(t_data *data)
{
	pthread_t	thread[data->param.nb_philos];
	t_philo		*philo_lst;
	t_philo		*philo;
	int			i;

	i = 0;
	philo_lst = NULL;
	while (i < data->param.nb_philos)
	{
		philo = init_philo(i + 1, data);
		if (!philo)
		{
			// free shit
			return (NULL);
		}
		append_philo(&philo_lst, philo);
		if (pthread_create(&thread[i], NULL, start_philo, \
		(void *)philo) == ERROR)
			return (NULL);
		pthread_detach(thread[i]);
		i++;
	}
	return (philo_lst);
}

int	create_threads(t_data *data)
{
	t_philo		*philo_lst;
	pthread_t	watch;

	philo_lst = create_philos(data);
	if (!philo_lst)
		return (ERROR);
	if (pthread_create(&watch, NULL, start_watch, \
	(void *)philo_lst) == ERROR)
			return (ERROR);
	if (pthread_join(watch, NULL) == ERROR)
	{
		// free shit
		return (ERROR);
	}
	return (SUCCESS);
}
