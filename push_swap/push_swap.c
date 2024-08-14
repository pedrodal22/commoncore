/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:12:40 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/14 20:24:10 by pfranco-         ###   ########.fr       */
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

void	initialize(int argc, int **array, int **array_index, int **copy)
{
	*array = malloc((argc - 1) * sizeof(int));
	*array_index = malloc((argc - 1) * sizeof(int));
	*copy = malloc((argc - 1) * sizeof(int));
}

void	sort_small(int argc, t_node **stack_a, t_node **stack_b)
{
	
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (sec_check(stack_a) == 1)
	{
		if (argc == 4)
			sort_3(stack_a);
		else if (argc == 6)
			sort_5(stack_a, stack_b);
	}
	else
		return ;
}

void sort_5(t_node **stackA, t_node **stackB)
{
    int pushed = 0;

    while (pushed < 2)
    {
        push_two(stackA, stackB, 1);
        pushed++;
    }
    sort_3(stackA);

    if ((*stackB)->indice_objtv == 0)
        rotate(stackB);

    while (*stackB != NULL)
        push_two(stackB, stackA, 2);// o problema tem que ser arranjado aqui
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
	if (sec_check(&stack_a) == 0 && check(argc, argv) == 1)
		write(2, "Error\n", 6);
	else
	{
		do_all(argc, argv, copy, array);
		put_index(argc, array, copy, array_index);
		in_st(argc, &stack_a, array, array_index);
		if (argc == 4 || argc == 6)
			sort_small(argc, &stack_a, &stack_b);
		else if (sec_check(&stack_a) == 0 || comparison(&stack_a, &stack_b) == 1)
			free_all(array, array_index, copy, stack_a);
	}
	free_all(array, array_index, copy, stack_a);
	return (0);
}
