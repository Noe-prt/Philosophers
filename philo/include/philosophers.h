/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:30:07 by nopareti          #+#    #+#             */
/*   Updated: 2025/01/31 15:58:58 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;

#ifndef NUM_MAX_OF_PHILO
#define NUM_MAX_OF_PHILO 200
#endif

int		ft_atoi(const char *str);
void    *philo_routine(void *arg);
int     ft_usleep(size_t milliseconds);
size_t	get_current_time(void);
void    init_philosophers(t_philo *philosophers, char **argv, t_program *program, pthread_mutex_t *forks);
void	init_program(t_program *program, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, int num_philos);
void 	*philo_routine(void *arg);
void 	destroy_forks_mutex(pthread_mutex_t *forks, int num_philos);
void 	destroy_program_mutex(t_program *program);
void	*monitor_routine(void *arg);
void	protected_message(char *str, t_philo *philo, int id);
int		is_philo_dead(t_philo *philo, size_t time_to_die);
int		check_philos_dead(t_philo *philos);
int		check_dead(t_philo *philo);
void	create_and_join_threads(t_program *program);
int		check_inputs_errors(int argc, char **argv);
int		check_philos_dead(t_philo *philos);
int		is_philo_dead(t_philo *philo, size_t time_to_die);
int		check_all_philos_ate(t_philo *philos);
int		check_dead(t_philo *philo);