/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:57:46 by pfranco-          #+#    #+#             */
/*   Updated: 2023/11/01 13:31:47 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_str(const char *s, char c)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			a++;
		}
		i++;
	}
	return (a);
}

static char	*get_str(char const *s, char *final, char c)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (s[a] != '\0' && s[a] != c)
	{
		a++;
	}
	final = malloc(a + 1);
	if (final == NULL)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
	{
		final[i] = s[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}

char	**ft_split(char const *s, char c)
{
	char	**final;
	int		i;
	int		k;

	i = 0;
	k = 0;
	final = malloc(sizeof(char *) * (nbr_str(s, c) + 1));
	if (final == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			final[k] = get_str(&s[i], final[k], c);
			k++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	final[k] = NULL;
	return (final);
}

/* int main() {
    char const *s = "  tripouille  42  ";
    char c = ' ';
    char **result = ft_split(s, c);

    if (result) {
        for (int i = 0; result[i] != NULL; i++) {
            printf("%s\n", result[i]);
            free(result[i]);
        }

        free(result);
    } else {
        printf("A alocação de memória falhou.\n");
    }

    return 0;
}
 */
