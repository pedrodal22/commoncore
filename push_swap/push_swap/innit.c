/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 23:59:09 by pedro             #+#    #+#             */
/*   Updated: 2024/08/16 00:05:17 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_index(int argc, int *array, int *copy, int *array_index)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (i < (argc - 1))
	{
		a = 0;
		while (a < (argc - 1))
		{
			if (array[i] == copy[a])
			{
				array_index[i] = a;
				break ;
			}
			a++;
		}
		i++;
	}
}

void	arrays(int argc, char **argv, int *array, int *copy)
{
	int	i;

	i = 0;
	while (i < (argc - 1))
	{
		array[i] = ft_atoi(argv[i + 1]);
		copy[i] = ft_atoi(argv[i +1]);
		i++;
	}
	i = 0;
}

void	in_st(int argc, t_node **stack_a, int *array, int *array_index)
{
	int	i;

	i = 0;
	while (i < (argc - 1))
	{
		stck_innit(stack_a, array[i], array_index[i]);
		i++;
	}
}

void	do_all(int argc, char *argv[], int *copy, int *array)
{
	arrays(argc, argv, array, copy);
	bubble_sort(copy, argc);
}
