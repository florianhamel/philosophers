/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:54:43 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/22 18:00:49 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*get_data(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->nb_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->max_meals = ft_atoi(av[5]);
	else
		data->max_meals = NO_ARG;
	return (data);
}

void	*start_philo(void *v_data)
{
	t_data	*data;

	data = (t_data *)v_data;
	return (NULL);
}

void	philo(t_data *data)
{
	pthread_t	threads[data->nb_philos];
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_create(&threads[i], NULL, start_philo, data);
		i++;
	}
}
