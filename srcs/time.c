/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:57:00 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/27 17:18:33 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_ms(struct timeval ref)
{
	struct timeval	tv;
	long			ms;

	if (gettimeofday(&tv, NULL) == ERROR)
		return (ERROR);
	ms = (tv.tv_sec - ref.tv_sec) * 1000;
	ms += (tv.tv_usec - ref.tv_usec) / 1000;
	return (ms);
}
