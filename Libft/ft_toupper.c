/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:00:41 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/16 15:47:55 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int i)
{
	if (i <= 'z' && i >= 'a')
	{
		i -= 32;
	}
	return (i);
}

/*
int main(void)
{
	char str[15] = "ola a todos!4";
	
	printf("%s\n", str);
	ft_strupcase(str);
	printf("%s", str);
}
*/