/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:40:58 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/06 14:09:53 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int count_word(char const *s)
{
    int i;
    i = 0;
    
    while (s[i] != '\0')
    {
        i++;
    }
    return(i++);
}

char **ft_split(char const *s, char c)
{
    int i;
    int sep_count;
    char **str;

    i = 0;
    sep_count = 0;
    while (s[i++] != '\0')
    {
        if (s[i] == c)
        {
            sep_count++;
        }
    }

    
}