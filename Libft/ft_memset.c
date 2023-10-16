/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:25:19 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/16 16:13:37 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*str;

	str = ptr;
	chr = c;
	
	while (n-- > 0)
	{
		*str++ = chr;
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
