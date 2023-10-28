#include "libft.h"

static char	*trim_start(char *copy, char *set, char *s1)
{
	int	i;
	int	a;
	int b;

	i = 0;
	a = 0;
	b = 0;
	while (!s1)
	{
		while (!s1 && a < ft_strlen(set))
		{
			if (s1[i] != set[a])
				a++;
			else
				a = 0;
				i++;
		}
		copy[b] = s1[i]; 
	}

	return (copy);
}
/*
static char	*trim_end(char const *s1, const char *set)
{
	int	a;
	int	k;
	int	set_size;
	int	str_size;

	a = 0;
	set_size = ft_strlen(set);
	str_size = trim_size(s1);
	while (k != 1)
	{
        while(str[a])
	}
	return (s1);
}
*/

/* static char	*trim_mem(char *s1)
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
} */

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


char	*ft_strtrim(char const *s1, char const *set)
{
	char	*final;
    char	*trimmed;
    char	*copy;
	unsigned int len;

	len = ft_strlen(s1) + 1;
    copy = malloc(len);
	if(copy != NULL)
	{
		ft_memcpy(copy, s1, len);
		trimmed = trim_start(copy, set, s1);
		trimmed = trim_end(trimmed, set, s1);
		final = trim_mem(trimmed);
	return (final);
	}
	return (NULL);
}

/* int main() {
    char input[] = "ab abcsfskfdac b";
    const char set[] = "a bc";
    char *result = ft_strtrim(input, set);

    printf("Result: '%s'\n", result);
    return 0;
} */

