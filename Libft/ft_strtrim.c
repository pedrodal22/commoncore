#include <stdio.h>
#include "libft.h"

char *trim_begin (char *s1_begin, char *set)
{
    int i;

    i = 0;
    if(s1_begin[i] = set[i])
    {
        s1_begin[i] = 0;
        i++;
    }
    return(s1_begin);
}

char *trim_end (char *s1_end, char *set)
{
    int i;

    i = ft_strlen(s1_end);
    a = ft_strlen(set);
    if(s1_end[i] = set[i])
    {
        s1_end[i] = 0;
        i--;
    }
    return(s1_end);
}

char *ft_strtrim(char const *s1, char const *set)
{
    char *s1_begin;
    char *s1_end;
    char *final;
    int i;
    int a;

    i = 0;
    a = 0;
    s1_begin = trim_begin(*s1);
    s1_end = trim_end(*s1);
    while(s1_begin == 0)
    {  
        i++;
    } 
    while(s1_begin != 0)
    {
        final[a++] = s1_begin[i++];
    }

}


void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	p;
	int	temp;

	i = 0;
	while (i < size)
	{
		p = i + 1;
		while (p < size)
		{
			if (tab[i] > tab[p])
			{
				temp = tab[i];
				tab[i] = tab[p];
				tab[p] = temp;
			}
			p++;
		}
		i++;
	}
}