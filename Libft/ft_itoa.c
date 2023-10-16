/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:16:38 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/16 15:35:12 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		temp;
	int		len;
	char	*str;

	len = 0;
	temp = n;
	while (temp != 0 && len++ != -1)
	{
		temp /= 10;
	}
	str = malloc(len + (n < 0) + 1);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	*(str + len++) = '\0';
	if (n == 0)
		*str = '0';
	while (n != 0)
	{
		str[len-- - 1] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

/*
int main()
{
    int n = -3242;
    printf("%s", itoa(n));
    return (0);
}
*/
