/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:12:40 by pfranco-          #+#    #+#             */
/*   Updated: 2024/07/02 14:36:12 by pfranco-         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	int		*array;
	int		*array_index;
	int		*copy;
	t_node	*stack_a;
	t_node	*stack_b;

	array = malloc((argc - 1) * sizeof(int));
	array_index = malloc((argc - 1) * sizeof(int));
	copy = malloc((argc - 1) * sizeof(int));
	stack_a = NULL;
	stack_b = NULL;
	if (check(argc, argv) == 1)
		write(STDERR_FILENO, "Error\n", 6);
	else
	{
		do_all(argc, argv, copy, array);
		put_index(argc, array, copy, array_index);
		in_st(argc, &stack_a, array, array_index);
		comparasion(&stack_a, &stack_b);
	}
	free_stacks(stack_a, stack_b);
	free_arrays(array, array_index, copy);
	return (0);
}

// void	print_stack(t_node *top)
// {
// 	int i;
// 	t_node *current;	
// 	i = 1;
// 	current = top;
// 	while (current != NULL) {
// 	    printf("Original %i: %d, Indice: %d\n", i, 
//current->original_value, current->indice_objtv);
//         current = current->next;
//         i++;
//     }
//     printf("-----\n\n");
// }
// printf("stack_a\n");
// print_stack(stack_a);
// printf("stack_b\n");
// print_stack(stack_b);
// comparasion(&stack_a, &stack_b);
// printf("stack_a\n");
// print_stack(stack_a);
// printf("stack_b\n");
// print_stack(stack_b);
