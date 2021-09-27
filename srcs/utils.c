/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:08:46 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/27 19:56:01 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_iseven(int nb)
{
	if (nb % 2 == 0)
		return (TRUE);
	return (FALSE);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return(len);
	while (str[len])
		len++;
	return (len);
}

int	ft_atoi(const char *str)
{
	unsigned long	nb;
	int				sign;
	int				i;

	if (!str)
		return (0);
	nb = 0;
	sign = 1;
	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return ((int)(sign * nb));
}
