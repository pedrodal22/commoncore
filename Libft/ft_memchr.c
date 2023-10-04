/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:56:05 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/04 17:42:23 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*str;

	i = 0;
	*str = (unsigned char *) s;
	while (n > 0)
	{
		if (str[i] == c)
		{
			return ((char *)&str[i]);
		}
		i++;
		n--;
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
