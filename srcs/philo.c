/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:54:43 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/24 18:17:22 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulation(t_param *param)
{
	t_data	*data;

	data->param = param;
	data->fork_lst = init_fork_lst(param);
	if (data->fork_lst)
		return (ERROR);
	if (create_threads(data) == ERROR)
	{
		free_fork_lst(data->fork_lst);
		return (ERROR);
	}
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
}
