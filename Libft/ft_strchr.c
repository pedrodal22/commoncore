/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:02:21 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/18 15:26:30 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr( char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (str[i] == c)
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}
