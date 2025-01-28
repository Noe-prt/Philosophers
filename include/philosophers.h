/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:27:40 by nopareti          #+#    #+#             */
/*   Updated: 2025/01/27 23:42:22 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

struct s_philosophers
{
    int number_of_philosophers;
    useconds_t time_to_die;
    useconds_t time_to_eat;
    useconds_t time_to_sleep;
    int numbers_of_time_each_philosophers_must_eat;
}           t_philosophers;