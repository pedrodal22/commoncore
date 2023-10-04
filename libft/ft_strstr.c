/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:03:16 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/04 15:26:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	a;
	int	b;

	a = 0;
	b = a;
	if (to_find[b] == '\0')
	{
		return (str);
	}
	while (str[a] != '\0')
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
	return (0);
}


int main(void)
{
    char to_find[] = "kjlkj";
    char str[] = "Ola a todos, hoje estamos aqui";
    char *result = ft_strstr(str, to_find);

    ft_strstr(str, to_find);
    printf("%s", result);
}

