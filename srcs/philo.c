/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:54:43 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/27 17:15:56 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulation(t_data *data)
{
	pthread_mutex_t	fork[data->param.nb_philos];
	int				i;

	i = 0;
	while (i < data->param.nb_philos)
	{
		if (pthread_mutex_init(&fork[i], NULL) == ERROR)
			return (ERROR);
		i++;
	}
	data->fork = fork;
	if (pthread_mutex_init(&data->write,  NULL) == ERROR)
		return (ERROR);
	if(gettimeofday(&data->start, NULL) == ERROR)
		return (ERROR);
	if (create_threads(data) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	philo(int ac, char **av)
{
	t_data	data;

	if (check_parsing(ac, av) == ERROR)
		return (ERROR);
	init_param(&data.param, ac, av);
	if (simulation(&data) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
