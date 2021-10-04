/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:54:43 by fhamel            #+#    #+#             */
/*   Updated: 2021/10/04 16:53:26 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_philo(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	while (philo->data->sb_died == FALSE)
	{
		if (!philo->data->sb_died && do_eat(philo) == ERROR)
			break ;
		if (!philo->data->sb_died && do_sleep(philo) == ERROR)
			break ;
		if (!philo->data->sb_died && do_think(philo) == ERROR)
			break ;
	}
	pthread_mutex_destroy(&philo->time);
	free(philo);
	return (NULL);
}

void	*start_nurse(void *void_lst)
{
	t_philo			*philo_lst;

	philo_lst = (t_philo *)void_lst;
	while (TRUE)
	{
		if (check_death(philo_lst) != FALSE)
			break ;
		if (check_meal(philo_lst) == TRUE)
			break ;
	}
	ft_usleep(250 * 1000);
	return (NULL);
}

int	simulation(t_data *data)
{
	data->sb_died = FALSE;
	if (gettimeofday(&data->start, NULL) == ERROR)
		return (ERROR);
	if (init_mutex(data) == ERROR)
		return (ERROR);
	if (create_threads(data) == ERROR)
		return (ERROR);
	data->sb_died = TRUE;
	free(data->fork);
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->death);
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
