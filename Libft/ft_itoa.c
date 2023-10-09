/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:16:38 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/06 13:37:11 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*itoa(int n)
{
    int temp;
    int len;
    char *str;

    len = 0;
    temp = n;
    while (temp != 0)
    {
        temp /= 10;
        len++;
    }
	if (n < 0)
	{
        str = malloc(len + 2);
		n = -n;
        len++;
        str[0] = '-';
	}
    else
    {    
        str = malloc(len + 1);
    }    
    *(str + len) = '\0';
    if (n == 0)
    {
        *str = '0';
    }
	while (n != 0)
	{
		str[len - 1] = n % 10 + '0';
        n /= 10;
        len--;
	}
    return (str);
}

int main()
{
    int n = 3242;
    printf("%s", itoa(n));
    return (0);
}