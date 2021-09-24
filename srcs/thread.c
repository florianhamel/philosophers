/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:19:00 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/24 19:24:29 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_thread(void *void_data)
{
	t_data	*data;

	data = (t_data *)void_data;
	return (NULL);
}

int	create_threads(t_data *data)
{
	pthread_t	thread[data->param->nb_philos];
	int			i;

	while (i < data->param->nb_philos)
	{
		if (pthread_create(thread[i], NULL, start_thread, \
		(void *)data) == ERROR)
			return (ERROR);
		i++;
	}
	while (i < data->param->nb_philos)
	{
	}
}
