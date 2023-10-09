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
            s1[i] = '\0';
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
            s1[s_size - 1] = '\0';
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

    while (s1[i] == '\0')
    {
        i++;
        h = i;
    }
    while (s1[i] != '\0')
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
    while (s1[h] != '\0')
    {
        final[a] = s1[h];
        a++;
        h++;
    }
    final[a] = '\0';
    return (final);
}

/*
int main() {
    char input[] = "  ab acbAHello, ashsb sddsgfd df dfbc World! A acb ca";
    const char set[] = "a bc";
    char *result = ft_strtrim(input, set);

    printf("Result: '%s'\n", result);
    return 0;
}
*/
