/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:27:05 by nopareti          #+#    #+#             */
/*   Updated: 2025/01/28 17:27:05 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine()
{
	usleep(2000);
	printf("philo routine\n");
	return (NULL);
}

t_philo	create_philo()
{
	t_philo	philo;


	pthread_create(&philo.thread, NULL, philo_routine, NULL);
	pthread_join(philo.thread, NULL);
	return (philo);
}