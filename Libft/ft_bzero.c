/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:59:17 by pfranco-          #+#    #+#             */
/*   Updated: 2023/11/18 15:36:11 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n-- > 0)
	{
		*str++ = '\0';
	}
}

/*
int main() {
    char str[20] = "Hello, World!";

    printf("String antes de bzero: %s\n", str);

    bzero(str, 20);

    printf("String depois de bzero: %s\n", str);

    return 0;
}
*/