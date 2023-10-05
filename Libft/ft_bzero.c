/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:59:17 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/05 14:59:02 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	int				a;
	unsigned char	*str;

	a = 0;
	*str = s;
	while (*str != '\0')
	{
		*str = 0;
		str++;
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
