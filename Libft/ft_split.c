/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:40:58 by pfranco-          #+#    #+#             */
/*   Updated: 2023/10/14 18:19:31 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

/*
char **ft_split(char const *s, char c)
{
    int i, start = 0;
    char **result;
    int size = ft_strlen(s) + 1;
    result = (char **)malloc(size);

    while(s[i] != '\0')
    {
        if(s[i] == c)
        {
            result[start] = ft_substr(s, start, i - start);
            start = i + 1;
        }
        else 
        {
            *result[i] = s[i];
        i++;
        }   
    }
    return (result);
}

int main ()
{
    char string[] = "Ola a todos hoje";
    char split = ' ';
    char *result = *ft_split(string, split);
    printf("%s", result);
}
*/


static int nbr_of_strs(char const *s, char c)
{
    int i;
    int a;
    
    i = 0;
    a = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            a++;
        }
        i++;
    }
    return(a);
}


int word_count(const char *s, char c)
{
    int i;
    
    i = 0;
    while (s[i] != '\0')
    {
        while (s[i] == c)
        {
            i++;
        }
         if (s[i] != '\0') 
        {
            while (s[i] != c && s[i] != '\0')
            {
                i++;
            }
        }
    }
    return (i);
}

char **ft_split(char const *s, char c)
{
    char **final;
    int i;
    int k;
    int a;
    int size;
    int mem;
    
    i = 0;
    a = 0;
    mem = nbr_of_strs(s, c);
    k = 0;
    size = ft_strlen(s);
    final = (char **)malloc(mem + 1);
    while (k < mem)
    {
        final[k] = (char *)malloc(mem);
        k++;
    }
    
    i = 0;
    while (s[i] != '\0')
    {
        a = 0;
        while (s[i] != c && s[i] != '\0')
        {
            final[k][a] = s[i];
            a++;
            i++;
        }
        final[k][a] = '\0'; 
        k++;
        
        if (s[i] == c)
            i++;
    }
    final[k] = NULL;
    
    return (final);
}

int main() {
    char const *s = "Esta e uma frase de exemplo";
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
