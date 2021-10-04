/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:19:00 by fhamel            #+#    #+#             */
/*   Updated: 2021/10/04 16:53:43 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philos(t_data *data, pthread_t *philo_thread)
{
	t_philo		*philo_lst;
	t_philo		*philo;
	int			i;

	i = 0;
	philo_lst = NULL;
	while (i < data->param.nb_philos)
	{
		philo = init_philo(i + 1, data);
		if (!philo)
			return (NULL);
		append_philo(&philo_lst, philo);
		if (pthread_create(&philo_thread[i], NULL, start_philo, \
		(void *)philo) == ERROR)
			return (NULL);
		pthread_detach(philo_thread[i]);
		if (ft_usleep(1 * 1000) == ERROR)
			return (NULL);
		i++;
	}
	free(philo_thread);
	return (philo_lst);
}

int	create_threads(t_data *data)
{
	t_philo		*philo_lst;
	pthread_t	*philo_thread;
	pthread_t	nurse;

	philo_thread = malloc(sizeof(pthread_t) * data->param.nb_philos);
	if (!philo_thread)
		return (ERROR);
	philo_lst = create_philos(data, philo_thread);
	if (!philo_lst)
		return (ERROR);
	if (pthread_create(&nurse, NULL, start_nurse, \
	(void *)philo_lst) == ERROR)
		return (ERROR);
	if (pthread_join(nurse, NULL) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}
