/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:56:05 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/18 19:06:13 by pedro            ###   ########.fr       */
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
    char *ptr = (char *)ft_memchr(str, 'W', sizeof(str));

    if (ptr != NULL) {
        printf("O caractere 'W' foi encontrado na posição %ld\n", ptr - str);
    } else {
        printf("O caractere 'W' não foi encontrado\n");
    }

    return 0;
}
*/
