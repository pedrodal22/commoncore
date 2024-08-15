/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:10:17 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/15 20:20:31 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	a = 1;
	while (a < argc)
	{
		i = 0;
		if (argv[a][0] == '-' || argv[a][0] == '+')
		{
			if (argv[a][1] < '0' || argv[a][1] > '9')
				return (1);
			i++;
		}
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

// int	sec_check(t_node **stackA)
// {
// 	t_node	*current;

// 	if (stackA == NULL || *stackA == NULL)
// 		return (0);
// 	current = *stackA;
// 	while (current->next != NULL)
// 	{
// 		if (current->indice_objtv > current->next->indice_objtv)
// 			return (1);
// 		current = current->next;
// 	}
// 	return (0);
// }

int	check_order(t_node **stackA)
{
	t_node	*current;

	if (stackA == NULL || *stackA == NULL)
		return (0);
	current = *stackA;
	while (current->next != NULL)
	{
		if (current->indice_objtv > current->next->indice_objtv)
			return (1);
		current = current->next;
	}
	return (0);
}
