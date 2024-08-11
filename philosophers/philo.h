/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:30:01 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/07 20:40:53 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_general
{
	int	nbr_philo;
	int	tm_die;
	int tm_eat;
	int	tm_sleep;
	int	x_eat;
}	t_general;

typedef struct s_philo
{
	int phil_index;
}	t_philo;

int		main(int argc, char **argv);
int		check_arguments(int argc, char **argv);
void	print_error(int error);

#endif