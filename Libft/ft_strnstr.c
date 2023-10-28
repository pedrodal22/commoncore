/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:28:25 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/19 20:55:07 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	a;
	unsigned int	b;

	a = 0;
	b = 0;
	if (little[b] == '\0')
	{
		return ((char *)big);
	}
	while ((unsigned char)big[a] != '\0' && a < len)
	{
		while ((unsigned char) little[b] != '\0'
			&& (unsigned char )big[a + b] == (unsigned char)little[b]
			&& a + b < len && big[a + b] != '\0')
		{
			b++;
		}
		if ((unsigned char) little[b] == '\0')
		{
			return ((char *)big + a);
		}
		a++;
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
