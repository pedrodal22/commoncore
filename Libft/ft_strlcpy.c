/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:00:02 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/16 17:43:37 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlcpy(char *dest, const char *src, size_t n)
{
	unsigned int	a;

	a = 0;
	n = a;
	while (a < n || src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0'; 
	return (dest);
}

/*
int	main(void)
{
	int		a;
	unsigned int		n;
	char	dest[20]; 
	char	src[20] = "Ola a todos";

	a = 0;
	n = a;
	printf ("Source string:  ");
	while (src[a] != '\0')
	{
		printf("%c", src[a]);
		a++;
	}
	ft_strlcpy(dest, src, n);
	printf("\nDestiny string:  ");
	a = 0;
	while (dest[a] != '\0')
	{
		printf("%c", dest[a]);
		a++;
	}
	return (0);
}
*/