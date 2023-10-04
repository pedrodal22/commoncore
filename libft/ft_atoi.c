/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:00:07 by pfranco-          #+#    #+#             */
/*   Updated: 2023/08/16 23:44:05 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	a;
	int	simb;
	int	result;

	a = 0;
	result = 0;
	simb = 1;
	while (str[a] == 32 || (str[a] <= 13 && str[a] >= 9))
	{
		a++;
	}
	while (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
		{
			simb *= -1;
		}
		a++;
	}
	while ((str[a] >= '0' && str[a] <= '9'))
	{
		result = result * 10 + (str[a] - '0');
		a++;
	}
	return (result * simb);
}


int main (void)
{
	char str[30] = "+- --168 4684";
	int numero = ft_atoi(str);
	printf("Numero: %d\n", numero);
}

