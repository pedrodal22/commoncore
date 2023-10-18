/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:02:52 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/18 15:40:47 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	a;

	a = 0;
	if (n == 0)
		return (0);
	while (s1[a] == s2[a] && (s1[a] != '\0') && (a < n - 1))
	{
		a++;
	}
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}

/*
int main(void)
{
	printf("%d", ft_strncmp("Ola a todos", "Ola a asofew", 10));
}
*/