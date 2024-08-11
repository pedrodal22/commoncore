/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:37:58 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/07 20:38:42 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_arguments(int argc, char **argv)
{
	int i;
	int ii;

	i = 1;
	ii = 0;
	while(i < argc)
	{
		if (argv[i][0] == '0' && argv[i][1] == '\0')
			return (1);
		while (argv[i][ii] != '\0')
		{
			if (argv[i][ii] <= 57 && argv[i][ii] >= 48)
				ii++;
			else
				return (1);
		}
		ii = 0;
		i++;
	}
	return (0);
}

void print_error(int error)
{
	if (error == 0)
		printf("There is a problem with the arguments");
}