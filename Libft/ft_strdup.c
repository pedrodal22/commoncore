/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:57:26 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/05 14:57:26 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strdup(char *src)
{
	int		b;
	char	*dup;

	b = 0;
	dup = (char *)malloc (ft_strlen(src));
	while (src[b] != '\0')
	{
		dup[b] = src[b];
		b++;
	}
	dup[b] = '\0';
	return (dup);
}


int main(void)
{
	char *str = "Ola a todos";
	char *dup;

	dup = ft_strdup(str);

	printf("%s\n", dup);
	free(dup);
	printf("%s\n", dup);
	printf("...");
}

