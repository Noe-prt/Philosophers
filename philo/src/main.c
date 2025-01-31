/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:55:50 by nopareti          #+#    #+#             */
/*   Updated: 2025/01/30 00:55:34 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	pthread_mutex_t		forks[NUM_MAX_OF_PHILO];
	t_program			program;
	t_philo				philos[NUM_MAX_OF_PHILO];

	if (check_inputs_errors(argc, argv) == 1)
		return (0);
	init_program(&program, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philosophers(philos, argv, &program, forks);
	create_and_join_threads(&program);
	destroy_forks_mutex(forks, ft_atoi(argv[1]));
	destroy_program_mutex(&program);
	return (0);
}
