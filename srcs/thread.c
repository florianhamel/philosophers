/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:19:00 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/30 13:02:01 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo_fork(t_philo *philo_lst)
{
	t_philo	*current;
	t_philo	*next;
	int		i;

	current = philo_lst;
	i = 0;
	while (i < current->data->param.nb_philos)
	{
		pthread_mutex_destroy(&current->data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&current->data->write);
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
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
			free_philo_fork(philo_lst);
			return (NULL);
		}
		append_philo(&philo_lst, philo);
		if (pthread_create(&thread[i], NULL, start_philo, \
		(void *)philo) == ERROR)
			return (NULL);
		pthread_detach(thread[i]);
		if (ft_usleep(2) == ERROR)
			return (NULL);
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
		free_philo_fork(philo_lst);
		return (ERROR);
	}
	return (SUCCESS);
}
