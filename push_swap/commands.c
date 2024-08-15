/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:35:02 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/16 00:02:24 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_two(t_node **fonte, t_node **destino, int i)
{
	push(fonte, destino);
	if (i == 1)
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
}

void	rotate_two(t_node **stack, int i)
{
	rotate(stack);
	if (i == 1)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	swap_two(t_node **stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	reverse_rotate_two(t_node **stackA)
{
	reverse_rotate(stackA);
	ft_printf("rra\n");
}
