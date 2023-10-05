/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:59:13 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/05 18:22:38 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	int				i;
	unsigned char	*cdest;
	unsigned char	*csrc;

	*cdest = (unsigned char *) str1;
	*csrc = (unsigned char *) str2;
	i = 0;
	while (csrc[i] != '\0' && i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (str1);
}

/*
int main()
{
    char source[] = "Hello, world!";
    char dest[] = "Goodbye, world!";
    int size = 5;
    
    printf("Source: %s\n", source);
    printf("Destination: %s\n", dest);

    ft_memmove(dest, source, size);

    printf("\n\nSource: %s\n", source);
    printf("Destination: %s\n", dest);

    return 0;
}
*/
