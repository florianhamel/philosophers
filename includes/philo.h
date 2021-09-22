/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 03:04:52 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/22 16:37:53 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

// Bools
# define FALSE 0
# define TRUE 1

# define NO_ARG -1

typedef struct s_data
{
	int	nb_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meals;
}		t_data;

// error.c
void	error_args(void);
int		check_val(char *str);
void	error_val(void);

// philo.c
void	*start_philo(void *data);
t_data	*get_data(int ac, char **av);
void	philo(t_data *data);

// utils.c
int		ft_strlen(char *str);
int		ft_atoi(const char *str);

#endif