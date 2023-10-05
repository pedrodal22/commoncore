/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:02:42 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/05 16:01:15 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		a;
	char	*result;

	i = 0;
	a = 0;
	result = malloc((ft_strlen(s1) + ft_strlen(s2)+ 1));
	if (result == NULL)
	{
		return (NULL);
	}
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	while (a < ft_strlen(s2))
	{
		result[i] = s2[a];
		a++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*
int main()
{
    const char *str1 = "Hello, ";
    const char *str2 = "World!";
    char *result = ft_strjoin(str1, str2);

    if (result != NULL)
    {
        printf("%s\n", result);
        free(result);
    }
    else
    {
        printf("Falha ao alocar memória para a string concatenada.\n");
    }

    return 0;
}
*/
