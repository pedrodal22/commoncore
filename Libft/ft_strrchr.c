/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:01:32 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/04 17:37:14 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	while (str[i] != str[0])
	{
		if (str[i] == c)
		{
			return ((char *)&str[i]);
		}
		i--;
	}
	return (NULL);
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
