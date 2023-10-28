/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:16:38 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/24 13:30:34 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int itoa_length(int n)
{
    int len;
    
    len = 0;
    while (n != 0)
    {
        n = n / 10;
        len++;
    }
    len++;
    return (len);
}

static void	write_nbr(long n, char *final, int *i)
{
	if (n > 9)
	{
		write_nbr(n / 10, final, i);
		write_nbr(n % 10, final, i);
	}
	else
		final[(*i)++] = n + 48;
}

char	*ft_itoa(int n)
{
	char	*final;
	int		i;
	long	nbr;

	i = 0;
	nbr = n;
	if (nbr < 0)
	{
		final = malloc((itoa_length(nbr) + 1));
		if (final == NULL)
			return NULL;
		final[i] = '-';
		i += 1;
		write_nbr(nbr * -1, final, &i);
	}
	else
	{
		final = malloc((itoa_length(nbr) + 1));
		if (final == NULL)
			return NULL;
		write_nbr(nbr, final, &i);
	}
	final[i] = '\0';
	return (final);
}

/* int main()
{
    int n = 148;
	char *result;
	result = ft_itoa(n);
    printf("%s \n", result);
    return (0);
} */
 