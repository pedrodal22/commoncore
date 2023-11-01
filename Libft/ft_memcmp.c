/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:24:41 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/30 16:30:20 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned int		a;
	unsigned char		*str1;
	unsigned char		*str2;

	str1 = (unsigned char *)(s1);
	str2 = (unsigned char *)(s2);
	a = 0;
	while (a < n)
	{
		if (str1[a] > str2[a])
		{
			return (1);
		}
		else if (str1[a] < str2[a])
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
