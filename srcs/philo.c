/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:54:43 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/30 16:10:58 by fhamel           ###   ########.fr       */
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
	t_philo			*philo_lst;

	philo_lst = (t_philo *)void_lst;
	while (TRUE)
	{
		if (watch_death(philo_lst) != FALSE)
			return (NULL);
		if (watch_meal(philo_lst) == TRUE)
			return (NULL);
	}
}

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
	if (gettimeofday(&data->start, NULL) == ERROR)
		return (ERROR);
	if (pthread_mutex_init(&data->write,  NULL) == ERROR)
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
