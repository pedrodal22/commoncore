/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:10:17 by pfranco-          #+#    #+#             */
/*   Updated: 2024/07/02 12:39:08 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *copy, int argc)
{
	int	i;
	int	a;
	int	temp;

	i = 0;
	a = 0;
	while (i < (argc - 1))
	{
		while (a < (argc - 1) - i - 1)
		{
			if (copy[a] > copy[a + 1])
			{
				temp = copy[a];
				copy[a] = copy[a + 1];
				copy[a + 1] = temp;
			}
			a++;
		}
		a = 0;
		i++;
	}
}

void	free_stacks(t_node *stackA, t_node *stackB)
{
	t_node	*temp;

	while (stackA)
	{
		temp = stackA;
		stackA = stackA->next;
		free(temp);
	}
	while (stackB)
	{
		temp = stackA;
		stackA = stackA->next;
		free(temp);
	}
}

void	free_arrays(int *array, int *array_index, int *copy)
{
	free(array);
	free(array_index);
	free(copy);
}

int	check_double(int argc, char **argv)
{
	int	a;
	int	i;

	a = 1;
	while (a < argc)
	{
		if (atoi_grande(argv[a]) == 1)
			return (1);
		a++;
	}
	a = 1;
	while (a < argc - 1)
	{
		i = a + 1;
		while (i < argc)
		{
			if (ft_atoi(argv[a]) == ft_atoi(argv[i]))
				return (1);
			i++;
		}
		a++;
	}
	return (0);
}

int	check(int argc, char **argv)
{
	int	i;
	int	a;

	i = 0;
	a = 1;
	if (argc <= 1)
		return (0);
	while (a < argc)
	{
		i = 0;
		if (argv[a][0] == '-')
			i++;
		while (argv[a][i] != '\0')
		{
			if (argv[a][i] < '0' || argv[a][i] > '9')
				return (1);
			else
				i++;
		}
		a++;
	}
	if (check_double(argc, argv) == 1)
		return (1);
	return (0);
}
