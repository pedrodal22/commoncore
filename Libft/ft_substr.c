/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:02:23 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/05 16:08:21 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*str;
	char			*sub;
	unsigned int	i;

	str = (unsigned char *) s;
	sub = malloc((len + 1) * 1);
	i = 0;
	if (sub != NULL)
	{
		while (i < len && str[start + i] != '\0')
		{
			sub[i] = str[start + i];
			i++;
		}
		sub[i] = '\0';
	}
	return (sub);
}

/*
int main()
{
    const char *source = "Hello, World!";
    char *substring = ft_substr(source, 3, 6);

    if (substring != NULL) {
        printf("%s\n", substring);
        free(substring); // Não esqueça de liberar a memória alocada
    } else {
        printf("Falha ao alocar memória para a substring.\n");
    }
    
    return 0;
}
*/
