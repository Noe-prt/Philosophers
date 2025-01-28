/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:27:40 by nopareti          #+#    #+#             */
/*   Updated: 2025/01/28 17:26:56 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int main(int argc, char **argv)
{
    if (argc < 5)
    {
        if (argc > 6)
        {
            printf("too many args!\n");
            return (0);
        }
        printf("Not enough args!\n");
        return (0);
    }
    // ARGS
    // number of philosophers
    // time to die
    // time to eat
    // time to sleep
    // (optional) number of times each philosophers must eat
}
