/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:19:00 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/25 20:22:53 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_philo(void *void_data)
{
	t_data	*data;
	int		id;

	data = (t_data *)void_data;
	id = data->id;
	usleep(1 * 1000000);
	printf("id: %d\n", id);
	return (NULL);
}

void	*start_dw(void *void_data)
{
	t_data	*data;

	data = (t_data *)void_data;
	while (TRUE)
	{}
	return (NULL);
}

int	create_threads(t_data *data)
{
	pthread_t	thread[data->param->nb_philos];
	pthread_t	death_watch;
	int			i;

	i = 0;
	while (i < data->param->nb_philos)
	{
		data->id = i;
		if (pthread_create(&thread[i], NULL, start_philo, \
		(void *)data) == ERROR)
			return (ERROR);
		pthread_detach(thread[i]);
		usleep(3000);
		i++;
	}
	if (pthread_create(&death_watch, NULL, start_dw, (void *)data) == ERROR)
			return (ERROR);
	pthread_join(death_watch, NULL);
	return (SUCCESS);
}