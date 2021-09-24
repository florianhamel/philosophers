/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 03:04:52 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/24 19:24:12 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

// Bools
# define ERROR -1
# define SUCCESS 0
# define FALSE 0
# define TRUE 1

# define NO_ARG -1

typedef struct s_param
{
	int	nb_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meals;
}		t_param;

typedef struct s_fork
{
	int				status;
	struct s_fork	*prev;
	struct s_fork	*next;
}		t_fork;

typedef struct s_data
{
	struct s_param	*param;
	struct s_fork	*fork_lst;
}		t_data;

// error.c
void	error_args(void);
void	error_val(void);
int		check_val(char *str);
int		check_parsing(int ac, char **av);

// init.c
void	free_fork_lst(t_fork *fork_lst);
t_fork	*init_fork_lst(t_param *param);
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