/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 03:04:52 by fhamel            #+#    #+#             */
/*   Updated: 2021/09/28 01:58:11 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

# define ERROR -1
# define SUCCESS 0
# define FALSE 0
# define TRUE 1
# define DEAD 
# define NO_ARG -1

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

typedef struct s_param
{
	int	nb_philos;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	max_meals;
}		t_param;

typedef struct s_data
{
	struct s_param	param;
	struct timeval	start;
	pthread_mutex_t	*fork;
	pthread_mutex_t	write;
}		t_data;

typedef struct s_philo
{
	int				id;
	struct timeval	last_meal;
	struct s_data	*data;
	struct s_philo	*prev;
	struct s_philo	*next;
}		t_philo;

// action.c
int		simulate_action(t_philo *philo, int flag, long time);
int		do_eat(t_philo *philo);
int		do_sleep(t_philo *philo);
int		do_think(t_philo *philo);

// error.c
void	error_args(void);
void	error_val(void);
int		check_val(char *str);
int		check_parsing(int ac, char **av);

// fork.c
int		unlock_first_fork(t_philo *philo);
int		unlock_second_fork(t_philo *philo);
int		lock_first_fork(t_philo *philo);
int		lock_second_fork(t_philo *philo);

// init.c
t_philo	*init_philo(int id, t_data *data);
void	append_philo(t_philo **philo_lst, t_philo *philo);
void	init_param(t_param *param, int ac, char **av);

// philo.c
void	*start_philo(void *void_philo);
void	*start_watch(void *void_lst);
int		simulation(t_data *data);

// thread.c
void	free_philo_fork(t_philo *philo_lst);
t_philo	*create_philos(t_data *data);
int		create_threads(t_data *data);

// time.c
int		ft_usleep(long micros);
int		is_dead(t_philo *philo);
long	get_ms(struct timeval ref);

// utils.c
int		ft_iseven(int nb);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);

#endif