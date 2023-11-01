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

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((start > (unsigned int)ft_strlen(s)) || len == 0)
	{
		sub = malloc (1);
		sub[0] = '\0';
		return (sub);
	}
	if (ft_strlen(s) - start >= len)
		sub = malloc((len + 1));
	else
		sub = malloc(ft_strlen(s) - start + 1);
	if (sub == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
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
