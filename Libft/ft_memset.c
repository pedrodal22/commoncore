/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:25:19 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/04 17:34:18 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str;

	*str = ptr;
	i = 0;
	while (i < n && str[i] != '\0')
	{
		str[i] = c;
		i++;
	}
	return (ptr);
}
/*
int main() {
    char str[40] = "Hello, World!";

    printf("String antes de meu_memset: %s\n", str);

    ft_memset(str, 'A', 4);

    printf("String depois de meu_memset: %s\n", str);

    return 0;
}
*/
