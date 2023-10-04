/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:28:25 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/04 15:54:33 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

char *ft_strnstr(const char *s, const char *k, size_t len)
{
	unsigned int	a;
	unsigned int	b;
    char *str = (char *) s;
    char *to_find = (char *) k;

	a = 0;
	b = a;
	if (to_find[b] == '\0')
	{
		return (str);
	}
	while (str[a] != '\0' && a < len)
	{
		while (str[a + b] != '\0' && str[a + b] == to_find[b])
		{
			b++;
			if (to_find[b] == '\0')
			{
				return (str + a);
			}
		}
		a++;
		b = 0;
	}
    return (NULL);
}

/*
int main(void)
{
    char to_find[] = "";
    char str[] = "Ola a todos, hoje estamos aqui";
    char *result = ft_strnstr(str, to_find, 4);

    printf("%s", result);
}
*/
