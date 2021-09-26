/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 03:04:52 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/25 20:11:42 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

// Bools
# define ERROR -1
# define SUCCESS 0
# define FALSE 0
# define TRUE 1
# define DEAD 

# define NO_ARG -1

typedef struct s_param
{
	int	nb_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meals;
}		t_param;

// typedef struct s_fork
// {
// 	pthread_mutex_t	mutex;
// 	struct s_fork	*prev;
// 	struct s_fork	*next;
// }		t_fork;

typedef struct s_data
{
	struct s_param	*param;
	pthread_mutex_t	*fork;
	struct timeval	*stv;
	int				id;
}		t_data;

typedef struct s_philo
{
	int				id;
	struct timeval	*lt_eat;
}		t_philo;

// error.c
void	error_args(void);
void	error_val(void);
int		check_val(char *str);
int		check_parsing(int ac, char **av);

// init.c
t_param	*init_param(int ac, char **av);

// philo.c
int		simulation(t_param *param);
int		philo(int ac, char **av);

// thread.c
int		create_threads(t_data *data);

// utils.c
int		ft_strlen(char *str);
int		ft_atoi(const char *str);

#endif