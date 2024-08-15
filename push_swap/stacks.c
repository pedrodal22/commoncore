/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:05:50 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/15 14:33:17 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stck_innit(t_node **top, int original_value, int indice_objtv)
{
	t_node	*new_node;
	t_node	*current;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->original_value = original_value;
	new_node->indice_objtv = indice_objtv;
	new_node->next = NULL;
	if (*top == NULL)
		*top = new_node;
	else
	{
		current = *top;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

void	push(t_node **fonte, t_node **destino)
{
	t_node	*temp;

	if (*fonte == NULL)
		return ;
	temp = *fonte;
	*fonte = (*fonte)->next;
	temp->next = *destino;
	*destino = temp;
}

void	rotate(t_node **top)
{
	t_node	*primeiro;
	t_node	*current;

	primeiro = *top;
	current = *top;
	if (*top == NULL || (*top)->next == NULL)
		return ;
	while (current->next != NULL)
		current = current->next;
	*top = primeiro->next;
	current->next = primeiro;
	primeiro->next = NULL;
}

void	reverse_rotate(t_node **top)
{
	t_node	*current;
	t_node	*penultimo;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	current = *top;
	penultimo = NULL;
	while (current->next != NULL)
	{
		penultimo = current;
		current = current->next;
	}
	if (penultimo != NULL)
		penultimo->next = NULL;
	current->next = *top;
	*top = current;
}

void	swap(t_node **top)
{
	t_node	*current;
	t_node	*segundo;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	current = *top;
	segundo = (*top)->next;
	current->next = segundo->next;
	segundo->next = current;
	*top = segundo;
}
