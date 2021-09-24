/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:55:49 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/24 18:16:28 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_fork_lst(t_fork *fork_lst)
{
	t_fork	*current;
	t_fork	*next;

	current = fork_lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

t_fork	*init_fork_lst(t_param *param)
{
	t_fork	*new_fork;
	int		i;

	i = 0;
	while (i < param->nb_philos)
	{
		new_fork = malloc(sizeof(t_fork));
		if ()
		i++;
	}
}

t_param	*init_param(int ac, char **av)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (!param)
		return (NULL);
	param->nb_philos = ft_atoi(av[1]);
	param->time_to_die = ft_atoi(av[2]);
	param->time_to_eat = ft_atoi(av[3]);
	param->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		param->max_meals = ft_atoi(av[5]);
	else
		param->max_meals = NO_ARG;
	return (param);
}
