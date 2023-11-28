/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:25:19 by pfranco-          #+#    #+#             */
/*   Updated: 2023/11/01 11:24:13 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n-- > 0)
	{
		((unsigned char *)ptr)[i] = c;
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
