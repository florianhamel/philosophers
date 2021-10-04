/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:55:49 by fhamel            #+#    #+#             */
/*   Updated: 2021/10/04 11:50:19 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(int id, t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	if (pthread_mutex_init(&philo->time, NULL) == ERROR)
		return (NULL);
	philo->id = id;
	philo->nb_meals = 0;
	philo->last_meal = data->start;
	philo->data = data;
	philo->prev = NULL;
	philo->next = NULL;
	return (philo);
}

void	append_philo(t_philo **philo_lst, t_philo *philo)
{
	t_philo	*current;

	if (!*philo_lst)
	{
		*philo_lst = philo;
		return ;
	}
	current = *philo_lst;
	while (current->next)
		current = current->next;
	philo->prev = current;
	current->next = philo;
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->param.nb_philos);
	if (!data->fork)
		return (ERROR);
	while (i < data->param.nb_philos)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) == ERROR)
			return (ERROR);
		i++;
	}
	if (pthread_mutex_init(&data->write, NULL) == ERROR)
		return (ERROR);
	if (pthread_mutex_init(&data->death, NULL) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

void	init_param(t_param *param, int ac, char **av)
{
	param->nb_philos = ft_atoi(av[1]);
	param->tt_die = ft_atoi(av[2]);
	param->tt_eat = ft_atoi(av[3]);
	param->tt_sleep = ft_atoi(av[4]);
	if (ac == 6)
		param->max_meals = ft_atoi(av[5]);
	else
		param->max_meals = NO_ARG;
}
