/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:58:37 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/16 15:54:45 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*cdest;
	unsigned char	*csrc;

	i = 0;
	cdest = (unsigned char *) dest;
	csrc = (unsigned char *) src;
	if (cdest == NULL && csrc == NULL)
		return (NULL);
	while (csrc[i] != '\0' && i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}

/*
int main()
{
    char source[] = "Hello, world!";
    int size = 5;
    char destination[size];

    ft_memcpy(destination, source, size);

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}
*/
