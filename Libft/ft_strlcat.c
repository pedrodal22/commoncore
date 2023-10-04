/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:00:22 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/04 15:00:25 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	con;

	con = 0;
	while (str[con] != '\0')
	{
		con++;
	}
	return (con);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	dlen;
	unsigned int	slen;

	a = 0;
	b = 0;
	while (dest[b] != '\0')
	{
		b++;
	}
	dlen = b;
	slen = ft_strlen(src);
	if (size == 0 || size <= dlen)
	{
		return (slen + size);
	}
	while (src[a] != '\0' && a < size - dlen - 1)
	{
		dest[b] = src[a];
		a++;
		b++;
	}
	dest[b] = '\0';
	return (dlen + slen);
}

/*
int main(void)
{
    char src[] = "Todos";
    char dest[] = "Ola a ";
	unsigned int size_s = ft_strlcat(dest, src, 20);

    printf("%u", size_s);
    return (0);
}
*/