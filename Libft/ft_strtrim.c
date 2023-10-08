/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:02:16 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/05 16:14:10 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char    *ft_strtrim(char *s1, const char *set)
{
    int    i;
    int a;
    int k;
    char *final;
    int size = ft_strlen(set);
    int s_size = ft_strlen(s1);

    i = 0;
    a = 0;
    k = 0;
    while (k != 1)
    {
        while(s1[i] != set[a] && a < size)
        {
            a++;
        }
        if (s1[i] == set[a])
        {
            s1[i] = 'A';
            i++;
            a = 0;
        }
        else
        {
            k++;
        }
    }
    a = 0;
    k = 0;
    while (k != 1)
    {
        while(s1[s_size - 1] != set[a] && a < size)
        {
            a++;
        }
        if (s1[s_size - 1] == set[a])
        {
            s1[s_size - 1] = 'A';
            s_size--;
            a = 0;
        }
        else
        {
            k++;
        }
    }

    i = 0;
    a = 0;
    int h;

    while (s1[i] == 'A')
    {
        i++;
        h = i;
    }
    while (s1[i] != 'A')
    {
        a++;
        i++;
    }
    final = malloc(a + 1);
    if (final == NULL)
    {
        return NULL;
    }
    a = 0;
    while (s1[h] != 'A')
    {
        final[a] = s1[h];
        a++;
        h++;
    }
    final[a] = '\0';
    return (final);
}

int main() {
    char input[] = "  ab acHello, abc World! acb ca";
    const char set[] = "a bc";
    char *result = ft_strtrim(input, set);

    printf("Result: '%s'\n", result);
    return 0;
}

/*
char	*ft_strtrim(char *s1, const char *set)
{
	int	i;
	int start;
	int end;
	char *final;
	int size;

	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	size = end - start + 1;
	while(s1[start] == *set)
	{
		start++;
	}
	while(s1[end] == *set)
	{
		end--;
	}
	final = malloc(end - start + 2);
	while(i < size && start < end)
	{
		final[i] = s1[start];
		i++;
		start++;
	}
	final[i] = '\0';
	return(final);
}
*/