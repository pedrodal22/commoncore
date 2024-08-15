/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:22:25 by pfranco-          #+#    #+#             */
/*   Updated: 2024/08/15 19:55:14 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_overflow(const char *str, long long result, int simbolo)
{
	long long	l_max;
	long long	l_min;
	int			dig_max;
	int			dig_m;

	l_max = INT_MAX / 10;
	l_min = INT_MIN / 10;
	dig_max = INT_MAX % 10;
	dig_m = -(INT_MIN % 10);
	if (simbolo == 1)
		return (result > l_max || (result == l_max && (*str - '0') > dig_max));
	else
		return (result > -l_min || (result == -l_min && (*str - '0') > dig_m));
}

int	atoi_grande(const char *str)
{
	long long	resultado;
	int			simbolo;

	resultado = 0;
	simbolo = 1;
	if (*str == '-')
	{
		simbolo = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (check_overflow(str, resultado, simbolo))
			return (1);
		resultado = resultado * 10 + (*str - '0');
		str++;
	}
	return (0);
}

long int	ft_atoi(const char *str)
{
	int			a;
	long int	simb;
	long int	result;	

	a = 0;
	result = 0;
	simb = 1;
	while (str[a] == 32 || (str[a] <= 13 && str[a] >= 9))
		a++;
	if (str[a] == '-')
	{
		simb *= -1;
		a++;
	}
	else if (str[a] == '+')
		a++;
	while ((str[a] >= '0' && str[a] <= '9'))
	{
		result = result * 10 + (str[a] - '0');
		a++;
	}
	return (result * simb);
}

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