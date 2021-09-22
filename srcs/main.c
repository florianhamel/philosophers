/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 03:04:30 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/22 18:28:37 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	i = 1;
	if (ac < 5 || 6 < ac)
	{
		error_args();
		return (EXIT_FAILURE);
	}
	while (av[i])
	{
		if (!check_val(av[i]))
		{
			error_val();
			return (EXIT_FAILURE);
		}
		i++;
	}
	data = get_data(ac, av);
	if (!data)
		return (EXIT_FAILURE);
	philo(data);
	free(data);
	return (EXIT_SUCCESS);
}
