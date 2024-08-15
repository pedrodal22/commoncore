/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:50:01 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/15 19:53:09 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	comparison(t_node **stackA, t_node **stackB)
{
	int				mask;
	int				i_nodes;
	int				i;

	mask = 1;
	i_nodes = numero_nodes(stackA);
	while (mask != 0)
	{
		i = 0;
		if (check_order(stackA) == 0)
			return (1);
		while (i < i_nodes)
		{
			if (((*stackA)->indice_objtv & mask) == 0)
				push_two(stackA, stackB, 1);
			else
				rotate_two(stackA);
			i++;
		}
		while (*stackB != NULL)
			push_two(stackB, stackA, 2);
		mask <<= 1;
	}
	return (0);
}

void sort_5(t_node **stackA, t_node **stackB)
{
	int pushed;

	pushed = 0;
	while (pushed < 2)
	{
        if ((*stackA)->indice_objtv == 0 || (*stackA)->indice_objtv == 1)
		{
            push_two(stackA, stackB, 1);
			pushed++;
		}
		else
			rotate_two(stackA);
	}
	if ((*stackB)->indice_objtv == 0)
		rotate_three(stackB);
	sort_3(stackA);
    push_two(stackB, stackA, 2);
    push_two(stackB, stackA, 2);
}

void	sort_3(t_node **stackA)
{
	int first;
	int second;
	int third;

	first = (*stackA)->indice_objtv;
	second = (*stackA)->next->indice_objtv;
	third = (*stackA)->next->next->indice_objtv;
	if (first > second && second < third && first < third)
		swap_two(stackA);
	else if (first > second && second > third)
	{
		rotate_two(stackA);
		swap_two(stackA);
	}
	else if (first > second && second < third && first > third)
		rotate_two(stackA);
	else if (first < second && second > third && first < third)
	{
		swap_two(stackA);
		rotate_two(stackA);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_two(stackA);
	
}