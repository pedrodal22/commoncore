/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:01:32 by pfranco-          #+#    #+#             */
/*   Updated: 2023/11/01 11:36:00 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (str[i] == (char )c)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}

/*
int main() {
    const char str[] = "Hello, World!";
    const char ch = 'o';

    char *result = strrchr(str, ch);

    if (result != NULL) {
        printf("O caractere '%c' esta na posição: %ld\n", ch, result - str);
    } else {
        printf("O caractere '%c' não foi encontrado na string.\n", ch);
    }

    return 0;
}
*/
