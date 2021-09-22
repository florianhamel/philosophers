/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 03:04:30 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/22 13:13:10 by fhamel           ###   ########.fr       */
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
		return (1);
	}
	while (av[i])
	{
		if (!check_val(av[i]))
		{
			error_val();
			return (2);
		}
		i++;
	}
	data = get_data(ac, av);
	if (!data)
		return (3);
	philo(data);
	free(data);
	return (0);
}