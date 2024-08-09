/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:04:09 by pfranco-          #+#    #+#             */
/*   Updated: 2024/07/02 09:59:31 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	numero_nodes(t_node **stackA)
{
	int		i;
	t_node	*current;

	i = 0;
	current = *stackA;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int	check_order(t_node **stackA)
{
	t_node	*current;
	t_node	*current_next;

	if (*stackA == NULL)
		return (0);
	current = *stackA;
	current_next = current->next;
	while (current_next != NULL)
	{
		if (current->indice_objtv > current_next->indice_objtv)
			return (1);
		current = current->next;
		current_next = current->next;
	}
	return (0);
}

void	push_two(t_node **fonte, t_node **destino, int i)
{
	push(fonte, destino);
	if (i == 1)
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
}

void	rotate_two(t_node **stackA)
{
	rotate(stackA);
	ft_printf("ra\n");
}

void	comparasion(t_node **stackA, t_node **stackB)
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
			break ;
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
}
