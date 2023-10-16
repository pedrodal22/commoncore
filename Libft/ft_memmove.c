/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:59:13 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/16 17:44:17 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned int	i;
	unsigned char	*cdest;
	unsigned char	*csrc;

	cdest = (unsigned char *)str1;
	csrc = (unsigned char *)str2;
	i = 0;
	if (cdest == csrc)
		return (cdest);
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (cdest);
}

/*
int	main(void)
{
	char	source[] = "Hello, world!";
	char	dest[] = "Goodbye, world!";
	int		size;

	size = 5;
	printf("Source: %s\n", source);
	printf("Destination: %s\n", dest);
	ft_memmove(dest, source, size);
	printf("\n\nSource: %s\n", source);
	printf("Destination: %s\n", dest);
	return (0);
}
*/
