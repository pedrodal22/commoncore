/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:02:16 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/09 16:33:47 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trim_start(const char *set, const char *s1)
{
	int	i;
	int	a;
	int	k;
	int	size;

	i = 0;
	a = 0;
	k = 0;
	size = ft_strlen(set) - 1;
	while (k != 1)
	{
		while (s1[i] != set[a] && a < size)
			a++;
		if (s1[i] == set[a])
		{
			a = 0;
			i++;
		}
		else
			k++;
	}
	return (i);
}

static int	ft_trim_end(const char *set, const char *s1)
{
	int	a;
	int	k;
	int	size;
	int	size_s1;

	a = 0;
	k = 0;
	size = ft_strlen(set);
	size_s1 = ft_strlen(s1) - 1;
	while (k != 1)
	{
		while (s1[size_s1] != set[a] && a < size)
		{
			a++;
		}
		if (s1[size_s1] == set[a])
		{
			a = 0;
			size_s1--;
		}
		else
			k++;
	}
	return (size_s1);
}

static char	*do_strim_start(char *copy, const char *set, const char *s1)
{
	int	i;
	int	size_s1;
	int	n;

	i = ft_trim_start(set, s1);
	size_s1 = ft_trim_end(set, s1);
	n = 0;
	while (i <= size_s1)
	{
		copy[n] = s1[i];
		n++;
		i++;
	}
	copy[n] = '\0';
	return (copy);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	int		trim_start;
	int		trim_end;

	trim_start = ft_trim_start(set, s1);
	if (((unsigned char)s1[0] == '\0' && (unsigned char)set[0] == '\0')
		|| trim_start == ft_strlen(s1) || (s1 == NULL || set == NULL))
	{
		copy = malloc(1);
		if (copy != NULL)
		{
			copy[0] = '\0';
			return (copy);
		}
		return (NULL);
	}
	trim_end = ft_trim_end(set, s1);
	copy = malloc(trim_end - trim_start + 2);
	if (copy != NULL)
	{
		copy = do_strim_start(copy, set, s1);
		return (copy);
	}
	return (NULL);
}

/* int main() {
    const char *s1 = "  \t \t \n   \n\n\n\t";
    const char *set = " \n\t";
    char *trimmed = ft_strtrim(s1, set);

    if (trimmed != NULL) {
printf("String após remoção de espaços: \"%s\"\n", trimmed);
    } else {
        printf("A alocação de memória falhou.\n");
    }

    return 0;
}
 */
