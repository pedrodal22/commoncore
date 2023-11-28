/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:02:21 by pfranco-          #+#    #+#             */
/*   Updated: 2023/11/18 15:13:33 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char )c)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (str[i] == (char )c)
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}
