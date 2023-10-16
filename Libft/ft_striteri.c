/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:35:27 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/16 15:50:36 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "libft.h"

char	*ft_striteri(char const *s, char (*f)(unsigned int, char))
{
	char	*final;
	int		i;
	int		size;

	size = ft_strlen(s);
	i = 0;
	final = malloc(size + 1);
	if (final == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		final[i] = f(i, s[i]);
		i++;
	}
	final[i] = '\0';
	return (final);
}
*/
