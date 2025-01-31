/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:06:20 by nopareti          #+#    #+#             */
/*   Updated: 2025/01/29 14:06:20 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	init_program(t_program *program, t_philo *philos)
{
	program->dead_flag = 0;
	program->philos = philos;
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
}

void	set_philos_mutex(t_philo *philo, int i,
		t_program *program, pthread_mutex_t *forks)
{
	philo->dead = &program->dead_flag;
	philo->dead_lock = &program->dead_lock;
	philo->meal_lock = &program->meal_lock;
	philo->write_lock = &program->write_lock;
	philo->l_fork = &forks[i];
	if (i == 0)
		philo->r_fork = &forks[philo->num_of_philos - 1];
	else
		philo->r_fork = &forks[i - 1];
}

void	init_philosophers(t_philo *philosophers, char **argv,
		t_program *program, pthread_mutex_t *forks)
{
	int	num_philo;
	int	i;

	num_philo = ft_atoi(argv[1]);
	i = 0;
	while (i < num_philo)
	{
		philosophers[i].id = i + 1;
		philosophers[i].last_meal = get_current_time();
		philosophers[i].time_to_die = ft_atoi(argv[2]);
		philosophers[i].time_to_eat = ft_atoi(argv[3]);
		philosophers[i].time_to_sleep = ft_atoi(argv[4]);
		philosophers[i].num_of_philos = num_philo;
		philosophers[i].eating = 0;
		philosophers[i].meals_eaten = 0;
		philosophers[i].start_time = get_current_time();
		if (argv[5] && ft_atoi(argv[5]) > 0)
			philosophers[i].num_times_to_eat = ft_atoi(argv[5]);
		else
			philosophers[i].num_times_to_eat = -1;
		set_philos_mutex(&philosophers[i], i, program, forks);
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	create_and_join_threads(t_program *program)
{
	int			i;
	pthread_t	monitor_thread;

	pthread_create(&monitor_thread, NULL, &monitor_routine, program->philos);
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		pthread_create(&program->philos[i].thread, NULL,
			&philo_routine, &program->philos[i]);
		i++;
	}
	pthread_join(monitor_thread, NULL);
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		pthread_join(program->philos[i].thread, NULL);
		i++;
	}
}
