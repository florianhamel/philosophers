/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:53:16 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/24 18:04:42 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_args(void)
{
	char	*str;

	str = "usage: ./philo nb_philo time_to_die time_to_eat time_to_sleep \
[max_meals]\n";
	write(STDERR_FILENO, str, ft_strlen(str));
}

void	error_val(void)
{
	char	*str;

	str = "philo: arguments must be in the range [0, 10000]";
	write(STDERR_FILENO, str, ft_strlen(str));
}

int	check_val(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 5)
		return (FALSE);
	while (str[i])
	{
		if (str[i] < '0' || '9' < str[i])
			return (0);
		i++;
	}
	if (10000 < ft_atoi(str))
		return (FALSE);
	return (TRUE);
}

int	check_parsing(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac < 5 || 6 < ac)
	{
		error_args();
		return (ERROR);
	}
	while (av[i])
	{
		if (check_val(av[i]) == ERROR)
		{
			error_val();
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}
