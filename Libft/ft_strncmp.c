/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:02:52 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/04 15:02:54 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	a;

	a = 0;
	while ((s1[a] != '\0' || s2[a] != '\0') && a < n)
	{
		if (s1[a] > s2[a])
		{
			return (1);
		}
		else if (s1[a] < s2[a])
		{
			return (-1);
		}
		a++;
	}
	return (0);
}

/*
int main(void)
{
	printf("%d", ft_strncmp("Ola a todos", "Ola a asofew", 10));
}
*/