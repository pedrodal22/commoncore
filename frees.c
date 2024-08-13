/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:55:40 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/10 18:23:59 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(int *array, int *array_index, int *copy, t_node *stack_a)
{
	free_stacks(stack_a);
	free_arrays(array, array_index, copy);
}

void	free_stacks(t_node *stackA)
{
	t_node	*temp;

	while (stackA)
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
	exit(0);
}
