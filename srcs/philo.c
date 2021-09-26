/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:54:43 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/25 20:14:20 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*init_fork_mutex(t_param *param)
{
	pthread_mutex_t	*fork;
	int	i;

	i = 0;
	fork = malloc(sizeof(pthread_mutex_t) * param->nb_philos);
	if (!fork)
		return (NULL);
	while (i < param->nb_philos)
	{
		if (pthread_mutex_init(&fork[i], NULL) == ERROR)
			return (NULL);
		i++;
	}
	return (fork);
}

int	simulation(t_param *param)
{
	t_data			*data;
	struct timeval	stv;

	data = malloc(sizeof(t_data));
	if (!data)
		return (ERROR);
	data->param = param;
	data->fork = init_fork_mutex(param);
	if (!data->fork)
		return (ERROR);
	if(gettimeofday(&stv, NULL) == ERROR)
		return (ERROR);
	data->stv = &stv;
	if (create_threads(data) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	philo(int ac, char **av)
{
	t_param	*param;

	if (check_parsing(ac, av) == ERROR)
		return (ERROR);
	param = init_param(ac, av);
	if (!param)
		return (ERROR);
	if (simulation(param) == ERROR)
		return (ERROR);
	free(param);
	return (SUCCESS);
}
