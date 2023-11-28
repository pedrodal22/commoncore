/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:01:06 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/16 15:47:56 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int i)
{
	if (i <= 'Z' && i >= 'A')
	{
		i += 32;
	}
	return (i);
}

/*
int main(void)
{
	char str[15] = "OLA  todos!4";
	
	printf("%s\n", str);
	ft_strlowcase(str);
	printf("%s", str);
}
*/