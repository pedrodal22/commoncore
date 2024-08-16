/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:12:40 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/16 00:05:26 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize(int argc, int **array, int **array_index, int **copy)
{
	*array = malloc((argc - 1) * sizeof(int));
	*array_index = malloc((argc - 1) * sizeof(int));
	*copy = malloc((argc - 1) * sizeof(int));
}

int	main(int argc, char *argv[])
{
	int		*array;
	int		*array_index;
	int		*copy;
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	initialize(argc, &array, &array_index, &copy);
	if (check(argc, argv) == 1)
		write(2, "Error\n", 6);
	else
	{
		do_all(argc, argv, copy, array);
		put_index(argc, array, copy, array_index);
		in_st(argc, &stack_a, array, array_index);
		if (argc == 4 || argc == 6)
			sort_small(argc, &stack_a, &stack_b);
		else if (order(&stack_a) == 0 || comparison(&stack_a, &stack_b) == 1)
			free_all(array, array_index, copy, stack_a);
	}
	free_all(array, array_index, copy, stack_a);
	return (0);
}
