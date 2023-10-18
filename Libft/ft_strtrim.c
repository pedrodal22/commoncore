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

static char	*trim_start(char *s1, const char *set)
{
	int	i;
	int	a;
	int	k;
	int	size;

	i = 0;
	a = 0;
	k = 0;
	size = ft_strlen(set);
	while (k != 1)
	{
		while (s1[i] != set[a] && a < size)
			a++;
		if (s1[i] == set[a])
		{
			s1[i++] = '\0';
			a = 0;
		}
		else
			k++;
	}
	return (s1);
}

static int	trim_size(char *s1)
{
	int	i;

	i = 0;
	while (s1[i] == '\0')
	{
		i++;
	}
	while (s1[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*trim_end(char *s1, const char *set)
{
	int	a;
	int	k;
	int	size;
	int	s_size;

	k = 0;
	a = 0;
	size = ft_strlen(set);
	s_size = trim_size(s1);
	while (k != 1)
	{
		while (s1[s_size - 1] != set[a] && a < size)
			a++;
		if (s1[s_size - 1] == set[a])
		{
			s1[s_size-- - 1] = '\0';
			a = 0;
		}
		else
			k++;
	}
	return (s1);
}

static char	*trim_mem(char *s1)
{
	int		i;
	int		a;
	int		h;
	char	*final;

	i = 0;
	a = 0;
	while (s1[i] == '\0')
	{
		i++;
		h = i;
	}
	while (s1[i] != '\0')
	{
		i++;
		a++;
	}
	final = malloc(a + 1);
	a = 0;
	while (s1[h] != '\0')
	{
		final[a++] = s1[h++];
	}
	final[a] = '\0';
	return (final);
}

char	*ft_strtrim(char *s1, const char *set)
{
	char	*final;

	s1 = trim_start(s1, set);
	s1 = trim_end(s1, set);
	final = trim_mem(s1);
	return (final);
}

/*
int main() {
    char input[] = "  ab acbAHello, World! A acb ca";
    const char set[] = "a bc";
    char *result = ft_strtrim(input, set);

    printf("Result: '%s'\n", result);
    return 0;
}
*/
