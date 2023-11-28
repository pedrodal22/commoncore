/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:56:05 by pfranco-          #+#    #+#             */
/*   Updated: 2023/11/18 15:59:17 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;

	i = 0;
	while (n > i)
	{
		if (((unsigned char *)s)[i] == (unsigned char )c)
		{
			return ((void *)s + i);
		}
		i++;
	}
	return (NULL);
}

/* 
int main() {
    const char str[] = "Hello, World!";
    char *ptr = (char *)ft_memchr(str, 'o', sizeof(str));

    if (ptr != NULL) {
        printf("%s\n", ptr);
    } else {
        printf("O caractere 'W' não foi encontrado\n");
    }

    return 0;
}
 */
