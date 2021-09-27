/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 03:04:30 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/27 22:28:21 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (check_parsing(ac, av) == ERROR)
		return (EXIT_FAILURE);
	init_param(&data.param, ac, av);
	if (simulation(&data) == ERROR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
