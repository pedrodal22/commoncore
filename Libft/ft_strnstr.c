/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:28:25 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/16 14:38:47 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *s, char *k, size_t len)
{
	unsigned int	a;
	unsigned int	b;

	a = 0;
	b = a;
	if (k[b] == '\0')
	{
		return (s);
	}
	while (s[a++] != '\0' && a++ < len)
	{
		while (s[a + b] != '\0' && s[a + b] == k[b])
		{
			b++;
			if (k[b] == '\0')
				return (s + a);
		}
		b = 0;
	}
	return (NULL);
}

/*
int main(void)
{
    char to_find[] = "hoje";
    char str[] = "Ola a todos, hoje estamos aqui";
    char *result = ft_strnstr(str, to_find, 4);

    printf("%s", result);
}
*/
